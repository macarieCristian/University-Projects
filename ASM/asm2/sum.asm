assume cs:Code, ds:Data
Data segment
TabHexa db "0123456789ABCDEF"
buffer db 6 dup (?)
handle dw ?
file db 'numbers.txt',0
no db ?
sum dw 0
sasesprezece db 16
tipar db ?,"$"
Data ends

Code segment
start:
push data 
pop ds
mov ah, 3dh
mov al, 0
mov dx, offset file
int 21h

mov handle, ax

mov ah, 3fh
mov bx, handle
mov cx, 6
mov dx, offset buffer
int 21h

mov SI, 0

label1:
	cmp si, 6
	je down
	mov ah, buffer[si]
	mov al, buffer[si]+1
	add si, 2
	cmp ah, '9'
	ja hexa
	sub ah, '0'
	jmp jump	
		hexa:
		sub ah, 87
	jump:
	cmp al, '9'
	ja hexa2
	sub al, '0'
	jmp jump2	
		hexa2:
		sub al, 87
	jump2:
	mov bl, al
	mov bh, 0
	mov al, ah
	mul sasesprezece
	add ax, bx
	add sum, ax
	jmp label1
	
	

	
down:
	mov ax,sum
	
		mov bx,offset TabHexa
		;al are deja val
		xlat TabHexa
		
	
	mov byte ptr tipar,al
	mov ah,09h
	mov dx,offset tipar
	int 21h
	
mov ax, 4c00h
int 21h
Code ends
end start

