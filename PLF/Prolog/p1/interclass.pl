
merge([H1,H2|T],L,R):-
    H1=:=H2,!,
    merge([H2|T],L,R).

merge(L,[H1,H2|T],R):-
    H1=:=H2,!,
    merge(L,[H2|T],R).

merge([],L,L):-!.
merge(L,[],L):-!.
merge([H|T],[H1|T1],[H|TR]):-
    H<H1,!,
    merge(T,[H1|T1],TR).
merge([H|T],[H1|T1],[H1|TR]):-
    H1<H,!,
    merge([H|T],T1,TR).
merge([H|T],[H1|T1],RL):-
    H1=:=H,!,
    merge([H|T],T1,RL).
