

equal([],[]):-!.
equal(_,[]):-fail,!.
equal([],_):-fail,!.
equal([H|T],L2):-
    member(H,L2),
    remove(L2,H,LR),
    equal(T,LR),!.

equal(L1,[H|T]):-
    member(H,L1),
    remove(L1,H,LR),
    equal(LR,T),!.

equal([H|_],[H1|T1]):-
    not(member(H,[H1|T1])),
    fail,!.

equal([H|T],[H1|_]):-
    not(member(H1,[H|T])),
    fail,!.


remove([],_,[]):-!.
remove([H|T],H,L):-
    remove(T,H,L),!.
remove([H|T],E,[H|TR]):-
    H=\=E,!,
    remove(T,E,TR).
