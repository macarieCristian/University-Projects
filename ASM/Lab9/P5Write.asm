ASSUME cs: code, ds:data
   ;5. Read the numbers a, b and c and compute and print on the screen a+b-c.
data SEGMENT public
	plus db "+$"
	equal db "=$"
	minus db "-$"
data ENDS
code SEGMENT public
   ;code - numele segmentului de cod
	public write
	; al=a bl=b cl=c bh=result
	write:
	;add al,48
	;add bl,48
	;add cl,48
	;add bh,48
	
	mov dl,al
	mov ah,02h
	int 21h
	
	mov dx, offset plus
	mov ah,09h
	int 21h
	
	mov dl,bl
	mov ah,02h
	int 21h
	
	mov dx, offset minus
	mov ah,09h
	int 21h
	
	mov dl,cl
	mov ah,02h
	int 21h
	
	mov dx, offset equal
	mov ah,09h
	int 21h
	
	mov dl,bh
	mov ah,02h
	int 21h
	
	ret
	
   
code ENDS
end