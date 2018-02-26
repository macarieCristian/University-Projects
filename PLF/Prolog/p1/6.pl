%test if set

set([]).
set([H|T]):-
    member(H,T),
    fail.
set([H|T]):-
    not(member(H,T)),
    set(T),!.

%remove first 3 occurences

remove(L,E,RL):-
    remove(L,E,3,RL).

remove([],_,_,[]):-!.
remove([E|T],E,OCC,L):-
    OCC=\=0,
    OCC1 is OCC-1,
    remove(T,E,OCC1,L),!.
remove([H|T],E,OCC,[H|TR]):-
    remove(T,E,OCC,TR),!.


divLC(A, B, R):-
    R is (A*B)/gcd(A,B).
