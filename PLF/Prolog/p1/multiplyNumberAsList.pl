
multi([],_,0,[]).
multi([H|T],VAL,CAR,[RH|RT]):-
    multi(T,VAL,CAR2,RT),
    RH is (H*VAL+CAR2) mod 10,
    CAR is (H*VAL+CAR2) div 10.

multi(L,VAL,[CAR|RL]):-
    multi(L,VAL,CAR,RL),
    CAR=\=0,!.

multi(L,VAL,RL):-
    multi(L,VAL,_,RL).


reverse([],RL,RL).
reverse([H|T],L1,RL):-
    L2 = [H|L1],
    reverse(T,L2,RL).


multi1(L,V,RL):-
    reverse(L,[],NL),
    multi1(NL,V,0,L2),
    reverse(L2,[],RL).

multi1([],_,CAR,[CAR]):-
    CAR=\=0,!.
multi1([],_,CAR,[]):-
    CAR=:=0,!.
multi1([H|T],V,CAR,[HR|TR]):-
    HR is (H*V+CAR) mod 10,
    CAR2 is (H*V+CAR) div 10,
    multi1(T,V,CAR2,TR).
