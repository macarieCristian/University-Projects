delete from TestRuns
delete from TestRunTables
delete from TestRunViews

--Test Competitions 1-table 1-view
exec deleteParticipating_Teams
exec executeTest TestCompetitions

--Test Competitions And Teams 2-tables 2-views
exec deleteParticipating_Teams
exec executeTest TestCompetitionsAndTeams

--Test Participating Teams 1-table 1-view
exec deleteAll
exec insertCompetitions 1000
exec insertTeams 1000
exec executeTest TestParticipating_Teams





exec executeTest TestAll



exec insertCompetitions 1000
exec insertTeams 1000
exec insertParticipating_Teams 1000

exec deleteParticipating_Teams

select * from View_GroupBy

exec deleteAll