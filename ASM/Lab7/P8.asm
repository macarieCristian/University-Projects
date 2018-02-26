ASSUME cs: code, ds:data
   ;8. Being given a string of bytes, build a string of words 
   ;which contains in the low bytes of the words the set of distinct 
   ;characters from the given string and in the high byte of a word 
   ;it contains the number of occurrences of the low byte of the word 
   ;in the given byte string.
   ;Ex: given the string: sir DB 2, 4, 2, 5, 2, 2, 4, 4 
   ;we should have the result: rez DW 0402h, 0304h, 0105h.
data SEGMENT
	sir db 2, 4, 2, 5, 2, 2, 4, 4
	lenSir EQU $-sir				;lungime sir
	vector dw lenSir/2 DUP(?)		;initializez vectorul destinatie
	revenire dw ?					;offsetul de inceput
	frec db ?						;variabila pt frecventa
	loopMareCx dw ?					;cx pentru bucla mare
data ENDS
code SEGMENT
   ;code - numele segmentului de cod
start:
   mov ax,data    ;adresa segmentului de date se copiaza in ax
   mov ds,ax    ;continutul lui ax se copiaza in ds
   mov di,offset sir
   mov si,offset sir
   mov ax,seg sir
   mov ds,ax
   mov es,ax
   mov loopMareCx,lenSir
   mov bp,0
   cld
   buclamare:
	   mov cx,loopMareCx
	   lodsb
		mov b,al	;primul byte in al e in b
		mov al,'a'	;se pune a in locul lui
		dec loopMareCx
		stosb
		mov frec,0	;initializez frec
		mov cx,lenSir
		mov revenire,si
		mov si,offset sir
	   bucla:
			lodsb		;iau un el din sir
			cmp al,'a'
			jz aici
			cmp al,b	;if al==b
			jnz diferit
			inc frec
			dec si
			mov di,si
			inc si
			mov al,'a'
			dec loopMareCx
			stosb
			diferit:	;else
			aici:
			inc si
	   loop bucla	; in b am elementul , in frec frecventa
	   mov si,revenire
	   mov cx,loopMareCx
	   cmp b,'a'
	   jz acolo
	   mov al,frec
	   mov byte ptr vector[bp],al
	   mov al,b
	   mov byte ptr vector[bp+1],al
	   add bp,2
	   acolo:
   loop buclamare
   mov ax,4C00h
   int 21h   ;finalul executiei programului
code ENDS
END start