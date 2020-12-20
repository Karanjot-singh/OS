org 0x7c00 ; BIOS boot origin 
; TODO: See where to disable to interrupts
; TODO: See where to do things with A10
main:

    ; I should DISABLE A20 here but who cares?

    ; SETTING UP STACK
    mov bp, 0x9000
    mov sp, bp

    ; PRINTING in 16 BIT MODE
    ; mov bx, MSG_1
    ; call print16

    call switch_to_pm

[ BITS 16 ]
%include "print16.nasm"
%include "gdt32.nasm"


switch_to_pm:
    
    cli
    ; I realised that I don't care about interrupts

    ;==============================================================================
    ;PREPARING TO ENTER PROTECTED MODE 

    ; Loading DT for 32 bit
    lgdt [GDT32.Pointer] 

    ; Changing CR0 bit to represent the shift to protected mode
    mov eax, cr0
    or eax, 0x1 ;
    mov cr0, eax

    ; I should ENABLE A20 here but I didn't disable :)

    ;==============================================================================
    ;ENTERS PROTECTED MODE 

    jmp GDT32.Code:ProtectedModeCode


[ BITS 32 ]
%include "print32.nasm"
%include "set_seg_register.nasm"

ProtectedModeCode:

    ; Setting up all the segment value for protected mode
    mov ax, GDT32.Data
    call set_seg_register

    ; Printing in Protected Mode
     ;mov edi, 0xb8000
     ;mov ebx, MSG_2
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

MSG_2 db "Hello world",0
MSG_1 db "In real", 0
MSG_3 db "I'm in the long mode"

times 510 - ($-$$) db 0 
dw 0xaa55