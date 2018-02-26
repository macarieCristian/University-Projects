
if OBJECT_ID('RoutesStations','U') is not null
	drop table RoutesStations
if OBJECT_ID('Stations','U') is not null
	drop table Stations
if OBJECT_ID('Routes','U') is not null
	drop table [Routes]
if OBJECT_ID('Trains','U') is not null
	drop table Trains
if OBJECT_ID('TrainsTypes','U') is not null
	drop table TrainsTypes

go

create table TrainTypes
	(TTID tinyint primary key identity(1,1),
	TTDescription varchar(500))

create table Trains
	(TID smallint primary key identity(1,1),
	TName varchar(500),
	TTID tinyint references TrainTypes(TTID))
	
create table [Routes]
	(RID smallint primary key identity(1,1),
	RName varchar(500) unique,
	TID smallint references Trains(TID))

create table Stations
	([SID] smallint primary key identity(1,1),
	SName varchar(500) unique)

create table RoutesStations
	(RID smallint references [Routes](RID),
	[SID] smallint references Stations([SID]),
	primary key(RID,[SID]),
	Arrival time,
	Departure time)

go

insert TrainTypes values('regio'),('interregio')
insert Trains values('t1',1),('t2',1),('t3',1)
insert [Routes] values('r1',1),('r2',2),('r3',3)
insert Stations values('s1'),('s2'),('s3')
insert RoutesStations(RID,[SID],Arrival,Departure) values
	(1,1,'9:50am','10:00am'),(1,2,'10:10am','10:20am'),(1,3,'11:00am','11:10am'),
	(2,1,'9:40am','9:50am'),						   (2,3,'12:00am','12:10am'),
							 (3,2,'10:05am','10:25am')

go

select * from TrainTypes
select * from Trains
select * from [Routes]
select * from Stations
select * from RoutesStations
go



create proc uspStationOnRoute @RName varchar(50),@SName varchar(50),@ATime time,@DTime time
AS
	declare @RID smallint = (select RID from [Routes] where RName=@RName),
	@SID smallint = (select [SID] from Stations where SName=@SName)
	--id rid is not null
	if exists(select * from RoutesStations where RID = @RID and [SID] = @SID)
		update RoutesStations
		set Arrival = @ATime,Departure=@DTime
		where RID = @RID and [SID] = @SID
	else
		insert RoutesStations(RID,[SID],Arrival,Departure)
		values(@RID,@SID,@ATime,@DTime)
go

select * from RoutesStations
 
exec uspStationOnRoute @Rname = 'r3',@SName = 's1', @ATime = '14:00',@DTime = '14:10'

go
--view 
create view vRoutesWithAllStations
as

select R.RName
from [Routes] R
where not exists
	(select S.[SID]
	from Stations S
	except
	select RS.[SID]
	from RoutesStations RS
	where RS.RID = R.RID)
go

select * from vRoutesWithAllStations

go

create function ufStationsWithOverlappingRoutes()
returns table
as
	return 
	select S.SName
	from  Stations S
	where S.[SID] in
		(
			select RS1.[SID]
			from RoutesStations RS1 inner join RoutesStations RS2 on RS1.[SID] = RS2.[SID] and RS1.RID < RS2.RID
			and RS1.Arrival <= RS2.Departure and RS1.Departure >= RS2.Arrival
		)
go

select * from ufStationsWithOverlappingRoutes()

