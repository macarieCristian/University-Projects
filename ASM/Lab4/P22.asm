ASSUME cs: code, ds:data
   ;a/2+b*b-a*b*c+e
   ;a,b,c-byte; e-doubleword
data SEGMENT
	a db 128
	b db 32
	c db 17
	e dd 234
	x db ?
	p dw ?
	q db 2
	k dw ?
	y dd ?
   ;data - segmentul de date in care vom defini variabilele
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   mov al,a 
   cbw
   idiv q
   mov x,al ;x=a/2
   mov al,b 
   imul b
   mov p,ax
   mov ax,x
   add p,ax ;p=x+b*b
   mov al,a 
   imul b 
   mov k,ax
   mov al,c
   cbw
   imul k 
   mov word ptr y,ax
   mov word ptr Y+2,dx ;y=a*b*c
   mov ax,p
   cwd
   sub ax,word ptr y
   sbb dx,word ptr y+2
   add ax,word ptr e
   adc dx,word ptr e+2 
   mov word ptr y,ax
   mov word ptr y+2,dx
   mov ax,4C00h
   int 21h   ;finalul executiei programului
code ENDS
END start