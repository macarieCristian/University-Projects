
if object_id('Domain','U')is not null
	drop table Domain
if object_id('Authors','U')is not null
	drop table Authors
if object_id('Librarys','U')is not null
	drop table Librarys
if object_id('Books','U')is not null
	drop table Books
if object_id('Writed','U')is not null
	drop table Writed

create table Domain
(D_id int primary key identity(1,1),
DDescription varchar(50))

create table Library
(L_id int primary key identity(1,1),
LName varchar(50),
LAddress varchar(50))

create table Authors
(A_id int primary key identity(1,1),
AName varchar(50))

create table Book
(B_id int primary key identity(1,1),
Title varchar(50),
ACDate date,
D_id int references Domain(D_id),
L_id int references Library(L_id))

create table Writed
(B_id int references Book(B_id),
A_id int references Authors(A_id),
primary key(B_id,A_id))



insert into Domain values ('funky'),('funny')
insert into Authors values ('A1'),('A2'),('A3')
insert into Library values ('L1','address1'),('L2','address2')
insert into Book values ('Title1','2011-02-02',1,1),('Title2','2013-02-02',1,2),('Title3','2009-02-02',2,1),('Title4','2011-02-02',2,2)
insert into Writed values (1,1),(2,2),(3,3),(4,1),(4,2),(4,3)

go

create proc associate @AName varchar(50),@BName varchar(50)
as
	declare @B_id int = (select b.B_id from Book b where b.Title = @BName)
	declare @A_id int = (select a.A_id from Authors a where a.AName = @AName)
	if @A_id is null
	begin
		insert into Authors values (@AName)
		set @A_id = (select a.A_id from Authors a where a.AName = @AName)
	end
	if (select count(*) from Writed w where w.A_id = @A_id and w.B_id = @B_id) != 0
	print 'The book-Author already associated'
	else
		insert into Writed values(@B_id,@A_id)

go

select * from Book
select * from Authors
select * from Writed

exec associate 'A4','Title2'

go

alter view numOfBooks
as
	select l.LName, count(b.B_id) as NumBooks
	from Book b
	inner join Library l on b.L_id = l.L_id
	where b.ACDate > '2010-01-01'
	group by l.LName
	having count(b.B_id) >= 1

select * from numOfBooks

go




alter function funct(@numAuthors int)
returns table
	return
	select top(100) l.LName as Libraria,l.LAddress as Adresa,b.Title as Titlu,@numAuthors as Num
	from Book b
	inner join Library l on b.L_id = l.L_id
	where (select count(*)
			from Writed w
			where w.B_id = b.B_id) = @numAuthors
	

go

select * from funct(3)



	





