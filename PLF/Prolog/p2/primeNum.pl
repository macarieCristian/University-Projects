prime(X):-
    X=:=2,
    !.

prime(X):-
    X>=2,
    prime(X,2).

prime(X,I):-
    I=:=X mod 2 + 1,!.

prime(X,I):-
    X mod I =:= 0,
    I =< X div 2,
    fail,!.

prime(X,I):-
    I2 is I+1,
    I2 =< X mod 2 + 1,
    prime(X,I2),!.

addTwice([],[]):-!.
addTwice([H|T],[H,H|TR]):-
    prime(H),
    addTwice(T,TR),!.
addTwice([H|T],[H|TR]):-
    not(prime(H)),
    addTwice(T,TR),!.
