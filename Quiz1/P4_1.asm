SECTION .DATA

SECTION .TEXT
    GLOBAL long_add

long_add:
	push	ebp			;Store the previous value
	mov 	ebp, esp	;
    mov 	eax, [ebp+8] 	; First argument received in edi and moved to eax
    add 	eax, [ebp+12] 	; Second argument received from esi added to eax
    add 	eax, [ebp+16] 	; thied argument received from edx added to eax
    add 	eax, [ebp+20] 	; Fourth argument received from ecx added to eax
    pop 	ebp				;			
    ret 			 	; The sum stored in eax is returned to the C program.
