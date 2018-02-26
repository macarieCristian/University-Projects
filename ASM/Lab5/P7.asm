ASSUME cs: code, ds:data
   ;7. The words A and B are given. Obtain the word C in the following way:
   ;- the bits 0-4 of C have the value 1
   ;- the bits 5-11 of C are the same as the bits 0-6 of A
   ;- the bits 12-15 of C are the same as the bits 8-11 of B
data SEGMENT
	a dw 1010101101101011b
	b dw 1000000011001111b
	c dw ?
   ;data - segmentul de date in care vom defini variabilele
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   mov ax,0000000000001111b
   mov c,ax
   mov ax,a
   and ax,0000000001111111b
   mov cl,5
   shl ax,cl
   or c,ax
   mov ax,b
   and ax,0000111100000000b
   mov cl,4
   shl ax,cl
   or c,ax
   mov ax,4C00h
   int 21h   ;finalul executiei programului
code ENDS
END start