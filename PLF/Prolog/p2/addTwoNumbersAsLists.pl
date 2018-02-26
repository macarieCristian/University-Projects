
add2([],[],0,[]).
add2([H|T],[H1|T1],C,[HR|TR]):-
    add2(T,T1,C2,TR),
    HR is (H+H1+C2) mod 10,
    C is (H+H1+C2) div 10.

addM(L1,L2,[C|RL]):-
    add2(L1,L2,C,RL),
    C=\=0,!.

addM(L1,L2,RL):-
    add2(L1,L2,C,RL),
    C=:=0,!.
