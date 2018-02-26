assume cs:code,ds:data
data segment
	TabHexa db '0123456789ABCDEF'
	a db 5Ah
	tipar db ?,?,'$'
	zece db 16
data ends 
code segment
start:
	mov ax,data
	mov ds,ax
	
	mov bx,offset TabHexa
	mov al,a
	mov ah,0
	
	div zece
	mov dl,ah
	mov dh,al
	mov al,dh
	xlat TabHexa
	mov byte ptr tipar,al
	
	mov al,dl
	xlat TabHexa
	mov byte ptr tipar+1,al
	
	
	mov ah,09h
	mov dx,offset tipar
	int 21h
	
	
	
	mov ax,4C00h
	int 21h
code ends
end start