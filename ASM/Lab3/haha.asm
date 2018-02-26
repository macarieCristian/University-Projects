ASSUME cs: code, ds:data
   ;spunem asamblorului care sunt segmentele folosite de noi
data SEGMENT
	a db 128
	b db 32
	d db 17
	x db ?
   ;data - segmentul de date in care vom defini variabilele
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   mov al,a		;al=a
   add al,b		;al=al+b
   sub al,d		;al=al-d
   mov x,al		;x=al
   mov al,a 	;al=a
   sub al,b 	;al=al-b
   sub al,d 	;al=al-d
   add x,al 	;x=x+a
   mov ax,4C00h
   int 21h   ;finalul executiei programului
code ENDS
END start