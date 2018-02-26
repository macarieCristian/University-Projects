ASSUME cs: code, ds:data
   ;5. Read the numbers a, b and c and compute and print on the screen a+b-c.
data SEGMENT public
	a db ?
	b db ?
	c db ?
	result db ?
data ENDS
code SEGMENT public
   ;code - numele segmentului de cod
extrn read:proc
extrn write:proc
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   
   call read
   mov a,al
   
   call read
   mov b,al
   
   call read
   mov c,al
   
   mov al,a
   add al,b
   sub al,c
   mov bh,al
   
   mov al,a
   mov bl,b
   mov cl,c
   mov bh,result
   
   call write
   
		mov ax,4C00h
		int 21h   ;finalul executiei programului
code ENDS
END start