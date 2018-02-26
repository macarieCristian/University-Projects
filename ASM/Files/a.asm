assume ds:data, cs:code
data segment public
	sir db 1,2,0,2,5,10,8,9,0,3,11,14,0
	l equ $ - sir
	maxLen dw 0
	maxSeq db l dup (?)
	public sir
	public maxLen
	public maxSeq
data ends
code segment public
extrn sequence:proc
start:
	mov ax, data
	mov ds, ax

	mov si, 0					;will be used as counter for the string
	mov di, 0					;will remember where the current sequence starts
	mov bx, 0					;will count the length of the current sequence

	call sequence

	mov ax, 4c00h
	int 21h
code ends
end start