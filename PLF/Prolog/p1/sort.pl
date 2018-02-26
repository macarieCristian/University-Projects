min([],[]).
min([H|T],R):-
    min(T,H,R).
min([],MIN,MIN).
min([H|T],MIN,R):-
    H<MIN,!,
    M is H,
    min(T,M,R).
min([H|T],MIN,R):-
    H>=MIN,
    min(T,MIN,R).

removeEl([],_,[]).
removeEl([H|T],H,L):-
    removeEl(T,H,L),!.
removeEl([H|T],EL,[H|TR]):-
    H=\=EL,!,
    removeEl(T,EL,TR).


sortm([],[]).
sortm(L,[HR|TR]):-
    min(L,M),
    HR is M,
    removeEl(L,M,NL),
    sort(NL,TR).
