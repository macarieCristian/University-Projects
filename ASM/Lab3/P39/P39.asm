ASSUME cs: code, ds:data
   ;spunem asamblorului care sunt segmentele folosite de noi
data SEGMENT
	a db 25
	d db 2
	b db 10
	c db 11
	x dw ?
   ;data - segmentul de date in care vom defini variabilele
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   mov al,a
   mul d
   mov x,ax
   mov al,b
   mul c
   add x,ax
   mov ax,4C00h
   int 21h   ;finalul executiei programului
code ENDS
END start