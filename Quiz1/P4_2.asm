SECTION .DATA

SECTION .TEXT
    GLOBAL extended_add

extended_add:
    mov 	eax, edi 	; First argument received in edi and moved to eax
    add 	eax, esi 	; Second argument received from esi added to eax
    add 	eax, edx 	; thied argument received from edx added to eax
    add 	eax, ecx 	; Fourth argument received from ecx added to eax
    ret 			 	; The sum stored in eax is returned to the C program.
