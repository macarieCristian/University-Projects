%reverseList(L-list,RL-reversed list)
%flow model (i,o)
reverse(L,R):-
    reverseList(L,[],R).
reverseList([],ACC,ACC).
reverseList([H|T],ACC,RL):-
    reverseList(T,[H|ACC],RL).

removeOccurences([],_,[]).
removeOccurences([H|T],E,[H|R]):-
    H=\=E,
    removeOccurences(T,E,R).
removeOccurences([H|T],E,R):-
    H=:=E,
    removeOccurences(T,E,R).

%toSet(L-list,S-resulted set)
%flow model (i,o)

%listToSet(l=(e1,e2,...,en),R)
%if l = vid => R=vid
%if e1 exist in (e2,...,en) => listToSet(l-e1,R+e1)
%if e1 not exist in (e2,...,en) => listToSet((e2,...,en),R)

listToSet([],[]).
listToSet([H|T],[H|SET]):-
    member(H,T), !,
    removeOccurences(T, H, R),
    listToSet(R,SET).
listToSet([H|T],[H|SET]):-
    listToSet(T,SET).

testListToSet:-
    listToSet([1,2,3,3,2,1],[1,2,3]),
    listToSet([1,2,1,3],[1,2,3]).
