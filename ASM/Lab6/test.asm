ASSUME cs: code, ds:data
   ;7. A byte string S is given. Obtain the string D1 which contains the elements found on the even positions of S and the string D2 which contains the elements found on the odd positions of S.
   ;Exemple:
   ;S: 1, 5, 3, 8, 2, 9
   ;D1: 1, 3, 2
   ;D2: 5, 8, 9
data SEGMENT
	s db "153829"
	len EQU $-s
	d1 db len DUP(?)
	d2 db len DUP(?)
   ;data - segmentul de date in care vom defini variabilele
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
	mov ax,data    ;adresa segmentului de date se copiaza in ax
	mov ds,ax    ;continutul lui ax se copiaza in ds
	mov cx,len
	jcxz final
	mov si,0
	mov di,0 ; par
	mov bx,0 ; impar
	bucla:
		mov dl,byte ptr s[si]
		test si,00000001b
		jz par
		mov byte ptr d2[di],dl
		inc di
		jmp over
		par:
			mov byte ptr d1[bx],dl
			inc bx
		over:
		inc si
	loop bucla
	final:
	mov ax,4C00h
	int 21h   ;finalul executiei programului
code ENDS
END start