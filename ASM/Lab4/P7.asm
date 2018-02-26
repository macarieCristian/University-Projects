ASSUME cs: code, ds:data
   ;(a-2)/(b+c)+a*c+e
   ;a,b-byte; c-word; e-doubleword
data SEGMENT
	a db 12
	b db 32
	c dw 17
	e dd 221
	x db ?
	y dw ?
	z dd ?
   ;data - segmentul de date in care vom defini variabilele
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   mov al,a
   sub al,2
   mov x,al
   mov al,b
   mov ah,0
   add ax,c
   mov y,ax
   mov al,x
   mov ah,0
   mov dx,0
   div y
   mov word ptr z,ax
   mov word ptr z+2,0
   mov al,a
   mov ah,0
   mul c
   add ax,word ptr z
   adc dx,word ptr z+2
   add ax,word ptr e
   adc dx,word ptr e+2
   mov word ptr z,ax
   mov word ptr z+2,dx
   mov ax,4C00h
   int 21h   ;finalul executiei programului
code ENDS
END start