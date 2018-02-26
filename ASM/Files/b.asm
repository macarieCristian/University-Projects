assume ds:data, cs:code
data segment public
	extrn sir:byte
	extrn l:word
	extrn maxLen:word
	extrn maxSeq:byte
data ends
code segment public
public sequence
sequence:
	mov si, 0					;will be used as counter for the string
	mov di, 0					;will remember where the current sequence starts
	mov bx, 0					;will count the length of the current sequence

	Again:
		cmp sir[si], 0				;compares the current byte with 0
		jne Continue				;if it is not 0, jumps to Continue
		
			;if it is 0, executes the following commands
		cmp bx, maxLen				;compares the length of the current sequence to the one
							;which is currently in maxSeq
		jna NotBigger				;if the it not greater, jumps to NotBigger

			;if the length is greater, executes the following commands
		mov cx, di				;cx = the bit where the sequence starts
		add cx, bx				;cx = the bit where the sequence ends
		mov maxLen, bx				;maxLen = bx = the maximum length
		mov bx, 0				;to be used as counter
		CopySeq:
			mov al, sir[di]
			mov maxSeq[bx], al		;copies the byte from sir to maxSeq
			add bx, 1			;bx = bx + 1
			add di, 1			;di = di + 1
			cmp di, cx			;compares di to the byte where the sequence ends
			jne CopySeq			;if it is not equal, repeats the loop
		mov bx, 0				;bx = 0
		NotBigger:
			add si, 1			;si = si + 1
			mov di, si			;di = si
			cmp si, l			;compares si to the length of the string
			jne Again			;if it is not equal, repeats the loop
		jmp Finish
		Continue:
			add bx, 1	;bx = bx + 1
			add si, 1	;si = si + 1
			jmp Again	;repeats the loop

	Finish:
	ret
code ends
end