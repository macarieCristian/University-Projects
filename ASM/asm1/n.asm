assume cs:code, ds:data

data segment
	msg1 db "Enter a string=",10,13,"$"
	
	maxLenght db 20
	realLenght db ?
	string db 20 dup (?)
	
	buffer db 100 dup (?),"$"
	
	openErrorMsg db "The file couldn't be open$"
	readErrorMsg db "A read error ocured$"
data ends
code segment
start:
	mov ax,data
	mov ds,ax
		
		;write msg1
		mov ah,09h
		mov dx,offset msg1
		int 21h
	
		;read string 
		mov ah,0ah
		mov dx,offset maxLenght
		int 21h
		
		jmp peste	;####################################mesaj
		;prepare string for printing
		mov al,realLenght
		mov ah,0
		mov si,ax
		mov string[si],10
		mov string[si+1],13
		mov string[si+2],"$"
		
		;print the string
		mov ah,09h
		mov dx,offset string
		int 21h
		peste: ;####################################mesaj
		
		;transform the file name into asciiz
		mov al,realLenght
		mov ah,0
		mov si,ax
		mov string[si],0
	
		;open the file
		mov ah,3dh
		mov al,2   ;open for reading and writing
		mov dx,offset string
		int 21h
		
		jc openErr ;if an error ocures
		mov bx,ax
		
		gogogo:   ;while not e of file we keep reading 100 bytes
			mov ah, 3fh
			mov dx, offset buffer
			mov cx,100
			int 21h
			
			jc readError ;if an read error ocures
			
			jmp dada ;jump peste mesaj####################################
			; after 3fh ax=the number of bytes readed
			mov si,ax
			mov buffer[si],"$"   ;prepare for writing
			
			;print the buffer
			mov ah,09h
			mov dx,offset buffer ;already in dx
			int 21h
			dada: ;###########################
			mov si,ax  ;pentru comparare
			
			mov ah,40h
			mov dx,offset buffer
			mov cx,100
			int 21h
			
			cmp si,100   ;to see if 100 bytes were read
			je gogogo
		
		
		jmp endProgram ;jump over the handeling code
		
		openErr:   ;handle the error
		mov ah,09h
		mov dx,offset openErrorMsg
		int 21h
		jmp endProgram
		
		readError:
		mov ah,09h
		mov dx,offset readErrorMsg
		int 21h
		jmp endProgram
	
	
	
	
	endProgram:
	
	mov ax,4C00h
	int 21h
code ends
end start