ASSUME cs: code, ds:data
   ;spunem asamblorului care sunt segmentele folosite de noi
data SEGMENT
	h db 25
	j db 2
	x dw ?
   ;data - segmentul de date in care vom defini variabilele
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   mov al,h
   mul 3
   add ax,10
   sub ax,80
   mov x,ax
   mov al,h
   mul j
   sub ax,15
   add x,ax
   mov ax,4C00h
   int 21h   ;finalul executiei programului
code ENDS
END start