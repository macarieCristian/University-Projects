% myCount(L-list,K-nr,R-nr of aparitions)
% myCount flow model (i,i,o)
myCount([],_,0).
myCount([H|T],K,R):-
    H=:=K,
    myCount(T,K,R2),
    R is R2+1.
myCount([H|T],K,R):-
    H=\=K,
    myCount(T,K,R).

%toSet(L-list,S-resulted set)
%flow model (i,o)
toSet(LIST,SET):-
    listToSet(LIST,[],SET).
listToSet([],ACC,ACC).
listToSet([H|T],ACC,SET):-
     member(H,ACC),
    listToSet(T,ACC,SET).
listToSet([H|T],ACC,SET):-
    listToSet(T,[H|ACC],SET).
