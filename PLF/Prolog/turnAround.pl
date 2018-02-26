turnAround([],[]).
turnAround([H|T],[HR|TR]):-
    turnAround(T,TR),
    HR is H.


