
exists([],_):-fail.
exists([E|_],E):-!.
exists([H|T],E):-
    H=\=E,
    exists(T,E).
