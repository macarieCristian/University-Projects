assume cs:code, ds: data
data segment
	time db ?, ?, ':', ?, ?, ' AM$'
data ends

code segment
start:
	mov ax, data
	mov ds, ax
	
	mov ah, 2Ch
	int 21h
	
	cmp ch, 12
	jg scade
	jmp prg

	scade:
		sub ch, 12
		mov time[6],'P'
		
	prg:
		mov ah, 0
		mov al, ch
		mov bl, 10
		div bl
		add al, 30h
		add ah, 30h
		mov time[0], al
		mov time[1], ah
		
		mov ah, 0
		mov al, cl
		mov bl, 10
		div bl
		add al, 30h
		add ah, 30h
		mov time[3], al
		mov time[4], ah
		
		mov ah, 09h
		mov DX, offset time
		int 21h
	
	mov AX, 4c00h
	int 21h
code ends
end start