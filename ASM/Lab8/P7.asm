ASSUME cs: code, ds:data
   ;7. Write a program which reads the name of a file from the keyboard and then it prints on the screen the even lines from this file.
data SEGMENT
	msg db 'Name of the file: $'
	maxFileName db 12
	lFileName db ?
	fileName db 12 dup (?)
	buffer db 1 dup (?), '$'
	openErrorMsg db 'Fisierul nu exista.$'
	readErrorMsg db 'Nu se poate citii din fisier.$'
	rowNumber db 0
	doi db 2
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   
   mov ah, 09h
   mov dx, offset msg
   int 21h				;printez mesajul msg
   
   mov ah, 0ah
   mov dx, offset maxFileName
   int 21h				;citesc de la tastatura numele fisierului
   
   mov al, lFileName
   xor ah, ah
   mov si, ax
   mov fileName[si], 0	;pune 0 la sfarsit
   
   mov ah, 3dh
   mov al, 0 	; open the file for reading 
   mov dx, offset fileName
   int 21h
   
   jc openError
   mov bx,ax
   
   merge:
		mov ah, 3fh
		mov dx, offset buffer
		mov cx, 1 ; citim maxim 1 caracter
		int 21h
		mov bx,ax	;salvez ax
		jc readError
		
		cmp buffer,10
		jne continua
		inc rowNumber
		continua:
		
		mov al,rowNumber
		mov ah,0
		div doi
		cmp ah,0
		jne nuTipareste
		
		mov si,bx
		mov buffer[si], '$'
		
		mov ah, 09h
		int 21h
		
		nuTipareste:
		
		cmp si, 1
		je merge
   
   jmp endPrg
   
   openError:
		mov ah, 09h
		mov dx, offset openErrorMsg
		int 21h
		jmp endPrg 
   
   readError:
		mov ah, 09h
		mov dx, offset readErrorMsg
		int 21h 
    
   endPrg:
		mov ax,4C00h
		int 21h   ;finalul executiei programului
code ENDS
END start