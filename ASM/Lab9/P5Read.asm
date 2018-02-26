ASSUME cs: code, ds:data
   ;5. Read the numbers a, b and c and compute and print on the screen a+b-c.
data SEGMENT public
	msg db "Enter a number: $"
data ENDS
code SEGMENT public
   ;code - numele segmentului de cod
   public read
   ; read a number and put it in al
   read:
   
   push bx
   push cx
   push dx
   
		mov dx,offset msg
        mov ah,09h
        int 21h
		
		mov ah,01h
		int 21h
   
   pop dx
   pop cx
   pop bx
   ret
   
code ENDS
end