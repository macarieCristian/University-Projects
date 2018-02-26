%union of 2 sets

union([],L2,L2).
union([H|T],L2,[H|TR]):-
    union(T,L2,TR).


addOne([],_,[]).
addOne([H|T],E,[[E,H]|TR]):-
    addOne(T,E,TR).


allPair(L,RL):-
    allPair(L,_,RL),!.

allPair([],LR,LR):-!.
allPair([H|T],R,LR):-
    addOne(T,H,L),
    append(R,L,NL),
    allPair(T,NL,LR),!.