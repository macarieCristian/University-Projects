% remove sequences of consecutive numbers

rs([],_,[]):-!.
rs([_],F,[]):-
    F=\=0,!.
rs([E],F,[E]):-
    F=:=0,!.

rs([H1,H2|T],_,LR):-
    H1=:=H2-1,!,
    F is 1,
    rs([H2|T],F,LR).

rs([H1,H2|T],F,RL):-
    H1=\=H2-1,!,
    F=:=1,
    F1 is 0,
    rs([H2|T],F1,RL).

rs([H1,H2|T],F,[H1|TR]):-
    H1=\=H2-1,!,
    F=:=0,
    rs([H2,T],TR).



del([], _, []):-!.

del([E], F, [E]):-
     F =:= 0,!.

del([_], F, []):-
     F =\= 0,!.

del([H1,H2|T], _, LR):-
     H1 =:= H2-1,!,
     F1 is 1,
     del([H2|T], F1, LR).

del([H1,H2|T], F, [H1|TR]):-
     H1 =\= H2-1,
     F =:= 0,
     del([H2|T], F, TR).


del([H1,H2|T], F, LR):-
     H1 =\= H2-1,
     F =:= 1,
     F1 is 0,
     del([H2|T], F1, LR).
