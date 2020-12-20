[ BITS 32 ]
%include "print32.nasm"
%include "gdt64.nasm"
%include "set_seg_register.nasm"
%include "paging.nasm"

print32:
    mov edx, cr0
    mov ecx, 32          ; 32 bits in a dword
    mov ebx, 000B8000h
.loop2:
    mov eax, 00000130h   ; BlueOnBlack "0"
    shl edx, 1           ; Top bit to the carry flag
    adc eax, 0           ; -> AL="0" or AL="1"
    mov [ebx], ax
    add ebx, 2
    dec ecx
    jnz .loop2
halt:
    cli
    hlt
    jmp halt
    ;mov rax, [0x00000043]
    ;hlt
