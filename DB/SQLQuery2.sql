create database Teacup
go
use TeaCup
go
create table Ingredients
(I_id int primary key identity,
Name varchar(50) not null,
Quantity int,
Price float)

create table Tea
(T_id int primary key,
Name varchar(50) default'Green',
Quantity int,
Price float,
I_id int foreign key references Ingredients(I_id)
)

create table Shops
(S_id int primary key,
Name varchar(50),
City varchar(50) not null,
)

create table ShopsTea
(S_id int foreign key references Shops(S_id),
T_id int foreign key references Tea(T_id),
constraint pk_ShopsTea primary key(S_id,T_id)
)

create table Managers
(M_id int foreign key references Shops(S_id),
Name varchar(50),
Experience int default 0,
constraint pk_Managers primary key(M_id)
)