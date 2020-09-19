SECTION .DATA

SECTION .TEXT
    GLOBAL long_add

long_add:
	push	ebp				;Store the previous value
	mov 	ebp, esp		; [ebp+4] is the return value
    mov 	eax, [ebp+8] 	; First argument received from stack [ebp+8] and moved to eax
    add 	eax, [ebp+12] 	; Second argument received from stack [ebp+12]  added to eax
    add 	eax, [ebp+16] 	; thied argument received from stack [ebp+16]  added to eax
    add 	eax, [ebp+20] 	; Fourth argument received from stack [ebp+20]  added to eax
    pop 	ebp				;			
    ret 			 		; The sum stored in eax is returned to the C program.
