%reverseList(L-list,RL-reversed list)
%flow model (i,o)
reverse(L,R):-
    reverseList(L,[],R).
reverseList([],ACC,ACC).
reverseList([H|T],ACC,RL):-
    reverseList(T,[H|ACC],RL).

