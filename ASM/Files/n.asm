assume cs:code, ds:data

data segment
	TabDec db '0123456789'
	fileName db "fisier.txt",0
	buffer db 100 dup (?)
	lenBuffer dw ?
	doi db 1
	result dw ?
	doidoi db 2
	mesaj db "Eroare la deschidere$"
	zece dw 10
data ends
code segment
start:
	mov ax,data
	mov ds,ax
		
		;open the file for reading
		mov ah,3dh
		mov al,0
		mov dx,offset fileName
		int 21h
		
		jc errorr
		mov bx,ax
		;read from file
		mov ah,3fh
		mov cx,100
		mov dx,offset buffer
		int 21h
		
		;ax=number of bytes read
		mov lenBuffer,ax
		mov cx,ax
		mov si,0
		transNumere:
			mov al,byte ptr buffer[si]
			sub al,'a'
			mov byte ptr buffer[si],al
			inc si
		loop transNumere
		
		
		mov si,lenBuffer
		bucla:
			mov al,byte ptr buffer[si-1]
			mul doi
			add result,ax
			mov al,doi
			mul doidoi
			mov doi,al
			dec si
		loop bucla
		
		mov cx,0
		printare:
			mov ax,result
			mov dx,0
			div zece
			mov result,ax
			
			mov bx,offset TabDec
			mov al,dl
			xlat TabDec
			mov ah,0
			push ax
			inc cx
			
			mov ax,result
		cmp ax,0
		jnz printare
		
		ptTipar:
			pop dx
			mov ah,02h
			int 21h
		loop ptTipar
		
		jmp endprog
		
		errorr:
		mov ah,09h
		mov dx,offset mesaj
		int 21h
		
		endprog:
	mov ax,4C00h
	int 21h
code ends
end start