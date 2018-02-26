assume cs:code, ds: data
data segment
	readFile db 'read.txt',0
	writeFile db 'write.txt',0
	
	readHandle dw ?
	writeHandle dw ?
	
	buffer db 10 dup (?)
	zece db 1
	numar dw ?
	ece dw 10
	printer db 10 dup (?)
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	
		mov ah,3dh
		mov al,0
		mov dx,offset readFile
		int 21h
		mov readHandle,ax
		
		mov ah,3dh
		mov al,1
		mov dx,offset writeFile
		int 21h
		mov writeHandle,ax
		
		mov ah,3fh
		mov bx,readHandle
		mov cx,10
		mov dx,offset buffer
		int 21h
		
		mov si,ax
		repeta:
			mov al,byte ptr buffer[si-1]
			sub al,'0'
			mul zece
			add numar,ax
			mov al,10
			mul zece
			mov zece,al
			dec si
			cmp si,0
		jne repeta
		
		add numar,2
		
		mov si,0
		repeta1:
			mov ax,numar
			mov dx,0
			div ece
			mov numar,ax
			add al,'0'
			mov ah,0
			push ax
			inc si
			mov ax,numar
			cmp ax,0
		jne repeta1
		mov di,0
		repeta2:
			pop ax
			mov byte ptr printer[di],al
			inc di
			dec si
			cmp si,0
		jne repeta2
		
		mov ah,40h
		mov bx,offset writeHandle
		mov cx,10
		mov dx,offset printer
		int 21h
	
	mov AX, 4c00h
	int 21h
code ends
end start