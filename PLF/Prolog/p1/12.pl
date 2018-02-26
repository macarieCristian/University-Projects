
%replace(L-list,V-value,EL-list,RL-result list)

add([],L,L).
add([H|T],L2,[H|TR]):-
    add(T,L2,TR).


replace([],_,_,[]).
replace([H|T],V,EL,[H|TR]):-
    H=\=V,!,
    replace(T,V,EL,TR).
replace([H|T],V,EL,RL):-
    H=:=V,!,
    add(EL,T,NT),
    replace(NT,V,EL,RL).

