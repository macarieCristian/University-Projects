; se citeste un caracter si un nume de fisier, sa se caute in fisier caracterul si sa se 
; afiseze pe ecran pozitia unde a fost gasit prima oara
assume cs:code, ds:data
data segment
	maxLenght db 20
	actualLenght db ?
	fileName db 20 dup (?)
	
	caracter db ?
	
	buffer db ?
	
	mesaj1 db 'Introduceti caracterul:','$'
	mesaj2 db 10,13,'Introduceti numele fisierului:','$'
	mesaj3 db 10,13,'Nu a fost gasit','$'
	mesaj4 db 10,13,'pozitia este:',10,13,'$'
	poz db ?,'$'
data ends
code segment
start:
mov ax,data
mov ds,ax
	
	mov ah,09h
	mov dx,offset mesaj1
	int 21h
	
	mov ah,01h
	int 21h
	;al =character
	mov caracter,al
	
	mov ah,09h
	mov dx,offset mesaj2
	int 21h
	
	mov ah,0ah
	mov dx,offset maxLenght	;read the filename
	int 21h
	
	mov al,actualLenght
	mov ah,0
	mov si,ax
	mov fileName[si],0
	
	mov ah,3dh
	mov al,0
	mov dx,offset fileName	;open the file
	int 21h
	;ax=filehandle
	
	mov si,0
	mov bx,ax
	bucla:
		mov ah,3fh
		mov cx,1
		mov dx,offset buffer
		int 21h
		;ax = number of bytes read
		cmp ax,0
		je peste
		inc si
		mov al,buffer
		mov ah,caracter
		cmp al,ah
		jne aici
			
			mov ah,09h
			mov dx,offset mesaj4
			int 21h
			
			mov ax,si
			add al,48
			mov poz,al
			mov ah,09h
			mov dx,offset poz
			int 21h
			
		jmp peste
		aici:
		
	jmp bucla
		
		mov ah,09h
		mov dx,offset mesaj3
		int 21h
	
	peste:



mov ax,4C00h
int 21h
code ends
end start