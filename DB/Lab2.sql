Use Rugby

/*All the teams that ever took part of Rugby World Cup*/
SELECT DISTINCT t.Name as 'Team Name',c.Name as 'Competition Name'
FROM Teams t
INNER JOIN Participating_Teams pt
ON pt.T_id=t.T_id
INNER JOIN Competitions c
ON c.C_id=pt.C_id
WHERE c.Name='Rugby World Cup'


/*All the teams with their managers and coaches, where managers have earnings>60.000*/
SELECT t.Name as 'Team Name',c.Name as 'Coach Name',m.Name as 'Manager Name',m.Earnings as 'Managers Earnings'
FROM Teams t
INNER JOIN Managers m
ON t.M_id=m.M_id
INNER JOIN Coaches c
ON t.C_id=c.C_id
WHERE m.Earnings>60000


/*All the players with sponsors from America*/
SELECT p.Name as 'Player Name',s.CompanyName as 'Company',s.Country
FROM Players p
INNER JOIN Sponsored_Players sp
ON p.P_id=sp.P_id
INNER JOIN Sponsors s
ON s.S_id=sp.S_id
WHERE s.Country='America'


/*All the teams which participated to  Rugby World Cup alongside with their sponsored players and their couch*/
SELECT DISTINCT t.Name as 'Team Name',co.Name as 'Coach Name',p.Name as 'Player Name',s.CompanyName as 'Sponsor',c.Name as 'Competition'
FROM Teams t
INNER JOIN Participating_Teams pt
ON t.T_id=pt.T_id
INNER JOIN Competitions c
ON c.C_id=pt.C_id
INNER JOIN Players p
ON p.T_id=t.T_id
INNER JOIN Sponsored_Players sp
ON p.P_id=sp.P_id
INNER JOIN Sponsors s
ON s.S_id=sp.S_id
INNER JOIN Coaches co
ON t.C_id=co.C_id
WHERE c.Name='Rugby World Cup'


/*All the teams with managers older than couches*/
SELECT t.Name as 'Team', m.Name as 'Manager Name', datediff(year,m.DateOfBirth,GETDATE()) as 'Manager Age', c.Name as 'Coach Name', datediff(year,c.DateOfBirth,GETDATE()) as 'Coach Age'
FROM Managers m
INNER JOIN Teams t
ON t.M_id=m.M_id
INNER JOIN Coaches c
ON c.C_id=t.C_id
WHERE datediff(year,m.DateOfBirth,GETDATE()) > datediff(year,c.DateOfBirth,GETDATE())


/*Get the weight per each team having more than 1 player and the number of suspended players for that team*/
SELECT t.Name as 'Team',SUM(p.Weight) as 'Team Weight',COUNT(s.Su_id) as 'Num. of Suspended Players'
FROM Players p
INNER JOIN Teams t
ON p.T_id=t.T_id
LEFT OUTER JOIN Suspended s
ON p.Su_id=s.Su_id
GROUP BY t.Name
HAVING COUNT(p.P_id)>1


/*Get the num. of competitions in which each team that have participed in more than 1 comp. took part*/
SELECT t.Name as 'Team',COUNT(c.C_id) as 'Num. of Competitions'
FROM Teams t
INNER JOIN Participating_Teams pt
ON t.T_id=pt.T_id
INNER JOIN Competitions c
ON c.C_id=pt.C_id
GROUP BY t.Name
HAVING COUNT(c.C_id)>1


/*Get all the players who have sponsors thier sponsors number and sum of money*/
SELECT p.Name as 'Player',COUNT(s.S_id) as 'Num. of Sponsors',SUM(sp.SumOfMoney) as 'Sum of Money'
FROM Players p
INNER JOIN Sponsored_Players sp
ON p.P_id=sp.P_id
INNER JOIN Sponsors s
ON s.S_id=sp.S_id
GROUP BY p.Name


/*All the sponsored players with their team who participated in Six Nations Championship with their addresses */
SELECT distinct p.Name as 'Player', s.CompanyName as 'Sponsor', c.Name as 'Competition', a.Country, a.City, a.Street, a.Number
FROM Players p
INNER JOIN Sponsored_Players sp
ON p.P_id=sp.P_id
INNER JOIN Sponsors s
ON s.S_id=sp.S_id
INNER JOIN Teams t
ON p.T_id=t.T_id
INNER JOIN Participating_Teams pt
ON t.T_id=pt.T_id
INNER JOIN Competitions c
ON c.C_id=pt.C_id
INNER JOIN Address a
ON a.A_id=p.A_id
WHERE c.Name IN ('Six Nations Championship', 'The Rugby Championship')


SELECT p.Name as 'Player Name', a.Country,a.City,a.Street,a.Number
FROM Players p
INNER JOIN Address a
ON p.A_id=a.A_id
WHERE a.Country='New Zealand'


