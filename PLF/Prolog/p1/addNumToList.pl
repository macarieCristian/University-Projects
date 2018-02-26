addN([],V,V,[]).
addN([H|T],V,CAR,[HR|TR]):-
    addN(T,V,CAR2,TR),
    HR is (H+CAR2) mod 10,
    CAR is (H+CAR2) div 10.

addN(L,V,[CAR|RL]):-
    addN(L,V,CAR,RL),
    CAR=\=0,!.

addN(L,V,RL):-
    addN(L,V,_,RL).
