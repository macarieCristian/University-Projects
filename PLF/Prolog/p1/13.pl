%list to set keeping the last occurence

removeL([],_,[]).
removeL([H|T],H,RL):-
    removeL(T,H,RL),!.
removeL([H|T],E,[H|TR]):-
    H=\=E,!,
    removeL(T,E,TR).

reverse([],L,L).
reverse([H|T],L,RL):-
    reverse(T,[H|L],RL).

a(L,R):-
    set(L,S),
    reverse(S,R).

set(L,RL):-
    reverse(L,NL),
    seti(NL,RL).
seti([],[]).
seti([H|T],[H|TR]):-
    removeL(T,H,NL),
    set(NL,TR).

