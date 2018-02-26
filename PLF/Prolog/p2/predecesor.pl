
elf([_|T],T).
f([H|_],H).

pred(L,RL):-
    pred(L,_,RL),
    f(RL,H),
    H =\= 0,!.

pred(L,RL):-
    pred(L,_,NL),
    f(NL,H),
    H =:= 0,
    elf(NL,RL),!.



pred([],1,[]):-!.
pred([H|T],C,[HR|TR]):-
    pred(T,C2,TR),
    H > 0,
    HR is H - C2,
    C is 0,!.

pred([H|T],C,[HR|TR]):-
    pred(T,C2,TR),
    H =:= 0,
    HR is (10 - C2) mod 10,
    C is C2,!.
