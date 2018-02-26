multiply([],_,[]).
multiply([H|T],K,[HR|TR]):-
    HR is H*K,
    multiply(T,K,TR).
