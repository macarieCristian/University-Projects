%splitList(L-list,EL-list of even nr,OL-odd numbers,NRE-num. of
% even,NRO-num. of odd)
%flow model (i,o,o,o,o)

%Formal model
%splitList(List=(e1,e2,...,en),ListE,ListO,NrE,NrO)
%if List = vid => ListE,ListO =vid and Nre,NrO=0
%if e1 is even => splitList((e2,...,en),e1+ListE,ListO,Nre+1,NrO)
%if e1 is odd => splitList((e2,...,en),ListE,e1+ListO,Nre,NrO+1)


splitList([],[],[],0,0).
splitList([HL|TL],[HEL|TEL],OL,NRE,NRO):-
    mod(HL,2) =:= 0,
    splitList(TL,TEL,OL,NRE2,NRO),
    HEL is HL,
    NRE is NRE2 + 1.
splitList([HL|TL],EL,[HOL|TOL],NRE,NRO):-
    mod(HL,2) =:= 1,
    splitList(TL,EL,TOL,NRE,NRO2),
    HOL is HL,
    NRO is NRO2 + 1.

testSplitList():-
    splitList([1,2,3],[2],[1,3],1,2),
    splitList([2,2,2],[2,2,2],[],3,0),
    splitList([],[],[],0,0).