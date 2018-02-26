if object_id('CinematicHeroes','U') is not null
	drop table CinematicHeroes
if object_id('Heroes','U') is not null
	drop table Heroes
if object_id('Companies','U') is not null
	drop table Companies
if object_id('Games','U') is not null
	drop table Games
if object_id('Cinematics','U') is not null
	drop table Cinematics

go

create table Companies
	(CID int primary key identity(1,1),
	CName varchar(50),
	CDescription varchar(50),
	Website varchar(50))

create table Games
	(GID int primary key identity(1,1),
	Gname varchar(50),
	ReleaseDate date,
	CID int references Companies(CID))

create table Cinematics
	(CIID int primary key identity(1,1),
	CIName varchar(50),
	GID int references Games(GID))

create table Heroes
	(HID int primary key identity(1,1),
	HName varchar(50),
	HDescription varchar(50),
	Importance varchar(50))

create table CinematicHeroes
	(CIID int references Cinematics(CIID),
	HID int references Heroes(HID),
	primary key(CIID,HID),
	EntryTime time)

go

insert into Companies values 
('Ubisoft','Gaming','www.u.com'),
('GaF','Gaming','www.f.com')

insert into Games values
('G1','2001-12-01',1),
('G2','2005-12-01',2),
('G3','2017-12-01',1),
('G4','1990-12-01',2)

insert into Cinematics values
('C1',1),
('C2',2),
('C3',3),
('C4',4)

insert into Heroes values
('Hero1','d','very'),
('Hero2','d','very'),
('Hero3','d','very'),
('Hero4','d','very'),
('Hero5','d','very')

insert into CinematicHeroes values
(1,1,'2:50'),
(1,2,'3:50'),
(2,3,'4:50'),
(3,1,'1:50')

go

select * from Games
select * from Companies
select * from Cinematics
select * from Heroes
select * from CinematicHeroes

go

create proc addCinematic @HName varchar(50),@CName varchar(50), @Moment time
as
	declare @HID int = (select h.HID from Heroes h where  h.HName = @HName)
	declare @CIID int = (select c.CIID from Cinematics c where c.CIName = @CName)
	if @CIID is null
	begin
		insert into Cinematics values(@CName,null)
		set @CIID = (select c.CIID from Cinematics c where c.CIName = @CName)
		insert into CinematicHeroes values(@CIID,@HID,@Moment)
	end
	else
	begin
		update CinematicHeroes 
		set EntryTime = @Moment
		where CIID = @CIID and HID = @HID
	end
go

select * from Cinematics
select * from Heroes
select * from CinematicHeroes

exec addCinematic 'Hero1','C1','1:00' 

go

create view vHeroesThatAppearAnywhere
as
	select h.HName,h.Importance
	from Heroes h
	where (select count(*)
			from CinematicHeroes ch
			inner join Cinematics c on ch.CIID = c.CIID
			where h.HID = ch.HID) = (select count(*)
									from Cinematics)

go

select * from vHeroesThatAppearAnywhere

go

alter function gameReleaseDate()
returns table
as
	return
	select c.CName,g.Gname,cc.CIName,g.ReleaseDate
	from Games g
	inner join Companies c on g.CID=c.CID
	inner join Cinematics cc on g.GID = cc.GID
	where g.ReleaseDate between '2000-12-02' and '2016-01-01'

go

select * from gameReleaseDate()






						

