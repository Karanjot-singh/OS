;Source index is use as a pointer to the current character being read in a string instruction
org 0x7C00                      ; to inform NASM to start at address 0x7c00
bits 16                         ; To inform the assembler that this is 16 bit mode
start:

    ; SETTING UP STACK
    mov bp, 0x9000
    mov sp, bp
	cli                     ; clear all interrupts
	mov si, msg             ; Source index now points to Hello world
	mov ah, 0x0E            ; Informs that we wnt to print chars

.loop:	
	; instruction to load a string byte at DS:SI register
	lodsb                   ; Loads SI into AL and increments SI [next char] 

	or al, al               ; Checks if the loaded string ended by al==0?
	jz nexti                 ; halts loop if al == 0 and hence end
	int 0x10                ; Else run bios interrupt 0x10 for video output service
	jmp .loop               ; loop continuation condition

nexti:
	hlt
    call switch_to_pm

[ BITS 16 ]
%include "gdt32.nasm"


switch_to_pm:
    
    cli
    ; Loading DT for 32 bit
    lgdt [GDT32.Pointer] 

    ; Changing CR0 bit to represent the shift to protected mode
    mov eax, cr0
    or eax, 0x1 ;
    mov cr0, eax
    ;==============================================================================
    ;ENTERS PROTECTED MODE 

    jmp GDT32.Code:PrintValueCR0


[ BITS 32 ]
%include "set_seg_register.nasm"

PrintValueCR0:

    ; Setting up all the segment value for protected mode
    mov ax, GDT32.Data
    call set_seg_register

    ; Printing in Protected Mode
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
MSG_1 db "Hello world", 0
msg:	db " Hello World ",0;


times 510 - ($-$$) db 0 
dw 0xaa55
	hlt

