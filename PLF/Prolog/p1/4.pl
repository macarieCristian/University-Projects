%difference of 2 sets
dif([],_,[]).
dif([H|T],L2,RL):-
    member(H,L2),!,
    dif(T,L2,RL).
dif([H|T],L2,[H|TR]):-
    dif(T,L2,TR).

%add 1 after every even number
add1([],[]).
add1([H|T],[H,1|TR]):-
    H mod 2 =:= 0,!,
    add1(T,TR).
add1([H|T],[H|TR]):-
    H mod 2 =:= 1,!,
    add1(T,TR).
