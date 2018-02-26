insert into Coaches(C_id,Name,DateOfBirth,Experience,History)
values
(1,'Andrew','1987-06-20',5,'Japan'),
(2,'Andy','1982-06-20',10,'New Zealand'),
(3,'John','1980-06-25',15,'South Africa'),
(4,'Matew','1987-08-20',5,'England'),
(5,'Andrew','1987-06-20',5,'Wales')

insert into Managers(M_id,Name,DateOfBirth,History,Earnings)
values
(1,'Richy','1980','New Zealand2',50000),
(2,'Mccow','1970','New Zealand',600000),
(3,'Sonny','1985','Japan',100000),
(4,'Frederic','1975','England',200000),
(5,'Uvuvwevwevwve','1972','South Africa',50000)

insert into Teams(T_id,Name,Num_of_players,C_id,M_id)
values
(1,'New Zealand',35,2,2),
(2,'New Zealand2',35,2,1),
(3,'South Africa',35,3,5),
(4,'Japan',35,1,3),
(5,'Wales',35,5,4),
(6,'Romania',35,1,1),
(7,'England',35,4,4),
(8,'France',35,4,3)

insert into Address(A_id,Country,City,Street,Number)
values
(1,'New Zealand','Wellington','Street1',12),
(2,'New Zealand','Wellington','Street2',10),
(3,'New Zealand','Jersy','Street3',11),
(4,'South Africa','Pretoria','Street4',7),
(5,'Japan','Tokyo','Street5',3),
(6,'Wales','Wellington','Street6',4),
(7,'England','London','Street7',6),
(8,'Romania','Cluj','Street8',8),
(9,'France','Paris','Street9',13),
(10,'France','Paris','Street10',12)

insert into Suspended(Su_id,Months,Reason)
values
(1,6,'Fight'),
(2,12,'Fight with referee'),
(3,2,'Dangerous play')

insert into Players(P_id,Name,DateOfBirth,Height,Weight,A_id,T_id,Su_id)
values
(1,'Richard','1990-08-19',190,100,1,1,null),
(2,'Sonny','1992-06-20',193,105,2,1,null),
(3,'Bill','1989-10-15',180,90,3,1,null),
(4,'John','1991-08-20',170,80,1,2,null),
(5,'Johny','1985-11-10',176,75,5,4,null),
(6,'Test','1990-05-19',182,85,5,4,null),
(7,'Franc','1986-12-17',192,102,4,3,null),
(8,'Richy','1987-04-13',186,90,4,3,null),
(9,'Sandu','1995-01-19',175,96,8,6,null),
(10,'Andrei','1996-05-20',190,110,8,6,null),
(11,'Serami','1993-08-19',184,100,6,5,1),
(12,'Salami','1994-09-11',179,80,8,6,1),
(13,'Berthrand','1996-12-19',193,104,7,7,null),
(14,'Arnold','1994-03-13',186,86,7,7,null),
(15,'Yeti','1992-02-19',194,107,7,7,null),
(16,'Poisson','1993-04-19',202,115,9,8,null),
(17,'Michel','1994-08-15',200,110,10,8,null),
(18,'Carter','1988-08-13',182,82,3,1,null),
(19,'Lomu','1985-03-19',196,120,2,1,null),
(20,'Pierr','1990-08-19',180,100,10,8,2)

insert into Competitions(C_id,Name,Prize,Date,Host_country,Description)
values
(1,'Rugby World Cup',30000000,'2014-05-21','New Zealand','Top of the rugby union competitons'),
(2,'Six Nations Championship',5000000,'2011-05-21','Argentina','Finest six teams'),
(3,'The Rugby Championship',1000000,'2013-05-21','South Africa','Nice to watch'),
(4,'Rugby World Cup',20000000,'2010-05-21','England','Top of the rugby union competitons'),
(5,'Six Nations Championship',5000000,'2012-05-21','New Zealand','Finest six teams')

insert into Sponsors(S_id,CompanyName,Country,Message)
values
(1,'Coca cola','America','We support the greatest teams'),
(2,'Pepsi','America','We support the finest teams'),
(3,'Fanta','America','Support real sport'),
(4,'BMW','Germany','German machines'),
(5,'Rover','America','We support rugby')

insert into Participating_Teams(C_id,T_id)
values
(1,1),
(1,3),
(1,4),
(1,5),
(1,6),
(1,7),
(1,8),
(2,1),
(2,3),
(2,7),
(2,8),
(3,1),
(3,3),
(3,2),
(3,4),
(3,7),
(4,1),
(4,3),
(4,4),
(4,5),
(4,6),
(4,7),
(4,8),
(5,1),
(5,3),
(5,7),
(5,8)

insert into Sponsored_Players(P_id,S_id,SumOfMoney)
values
(1,1,100000),
(2,1,90000),
(3,1,70000),
(18,1,200000),
(4,2,60000),
(12,2,100000),
(15,2,50000),
(19,5,200000),
(20,5,150000),
(19,4,100000),
(1,3,60000)



