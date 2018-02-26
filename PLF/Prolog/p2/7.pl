%poz of the max element

max([H|T],R):-
    maxE(T,H,R).

maxE([],M,M).
maxE([H|T],M,R):-
    M<H,
    M2 is H,
    maxE(T,M2,R),!.
maxE([H|T],M,R):-
    not(M<H),
    maxE(T,M,R),!.

pozMax([],[]):-!.
pozMax(L,R):-
    max(L,M),
    pozMax(L,1,M,R).

pozMax([],_,_,[]).
pozMax([H|T],C,H,[C|TR]):-
    C2 is C+1,
    pozMax(T,C2,H,TR),!.
pozMax([H|T],C,M,R):-
    H=\=M,!,
    C2 is C+1,
    pozMax(T,C2,M,R).
