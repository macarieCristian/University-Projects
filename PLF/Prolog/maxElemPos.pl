%maxElem((l1,...,ln),ACC)
%{ACC , l=[]
%maxElem((l2,...,ln),l1) , l1>ACC
%maxElem((l2,...,ln),ACC) , l1<ACC}
%maxElem(L-list,Max - max el.)
%flow model (i,o)
maxE([H|T],M):-
    maxE(T,H,M).
maxE([],A,A).
maxE([H|T],A,M):-
    H>A,!,
    maxE(T,H,M).
maxE([H|T],A,M):-
    H=<A,
    maxE(T,A,M).

testMaxE:-
    maxE([1,2,3],3),
    maxE([4,5,12,4],12).

%maxEPozList((l1,...,ln),M-max nr.,Idx-index, R-list)
%{[] , l=[]
%maxEPozList((l2,...,ln),M,Idx+1,add(R,Idx)),l1=M,
%maxEPozList((l2,...,ln),M,Idx+1,R),l1!=M}
% List of poz of maximal value(L-list,M-max value,Idx - index,Result-List)
% flow model: (i,i,i,o)
maxEPoz(L,R):-
    maxE(L,M),
    maxEPoz(L,M,1,R).
maxEPoz([],_,_,[]).
maxEPoz([H|T],M,C,[HR|HT]):-
    H=:=M,!,
    HR is C,
    C1 is C+1,
    maxEPoz(T,M,C1,HT).
maxEPoz([H|T],M,C,R):-
    H=\=M,
    C1 is C+1,
    maxEPoz(T,M,C1,R).

%modify((l1,...,ln))
%{maxEPoz(l1)+modify((l2,...,ln),is_list(l1)
%modify((l2,...,ln)),number(l1)}
%modify(L-list,RL -resultList)
%flow model: (i,o)
modify([],[]).
modify([H|T],[HR|TR]):-
    is_list(H),!,
    maxEPoz(H,NL),
    addList(NL,HR),
    modify(T,TR).
modify([H|T],[HR|TR]):-
    number(H),
    HR is H,
    modify(T,TR).

addList([],[]).
addList([H|T],[HR|TR]):-
    HR is H,
    addList(T,TR).

testModify:-
    modify([1,2,[2,3],5,[4,5,5]],[1,2,[2],5,[2,3]]),
    modify([],[]),
    modify([1,2,3,4,5],[1,2,3,4,5]).



