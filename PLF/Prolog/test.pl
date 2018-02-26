
min([H|T],M):-
    min(T,H,M).

min([],M,M):-!.
min([H|T],M,R):-
    H<M,
    M2 is H,
    min(T,M2,R),!.
min([H|T],M,R):-
    H>=M,
    min(T,M,R),!.

remove([],_,[]):-!.
remove([H|T],H,RL):-
    remove(T,H,RL),!.
remove([H|T],M,[H|TR]):-
    H=\=M,
    remove(T,M,TR),!.

sortacc([],[]):-!.
sortacc(L,[HR|TR]):-
    min(L,MIN),
    HR is MIN,
    remove(L,MIN,NL),
    sortacc(NL,TR),!.


test:-
    sortacc([4,2,6,2,3,4],[2,3,4,6]),
    sortacc([5,4,3,2,1],[1,2,3,4,5]),
    sortacc([1,2,4,2,1],[1,2,4]),
    sortacc([6,1,1,2,2,3,3,4,5,5,3,1],[1,2,3,4,5,6]).