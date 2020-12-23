org 0x7C00                          ; to inform NASM to start at address 0x7c00
bits 16                             ; To inform the assembler that this is 16 bit mode

start:
    ; To set stack ptr and base ptr
    mov bp , 0x9000
    mov sp , bp
    mov bx , MSG_1
    call print_hello

    call printcr0

[ BITS 16  ]
%include "gdt32.nasm"

print_hello:
    pusha       
    ; push to stack    
    mov ah , 0x0E 
    ; Informs that we wnt to print chars
    .loop:
        mov al , [bx ]         
        cmp al , 0   
        ; Checks if the loaded string ended by al==0? 
        je ret_back
        ;then end
        int 0x10    
        ; Else run bios interrupt 0x10 for video output service   
        add bx , 1   
        ;ctr increment
        jmp .loop
        ; loop continuation condition

    ret_back:
        mov al , 0x0a 
        ;update al value
        int 0x10
        ; run bios interrupt 0x10 for video output service   
        mov al , 0x0d 
        int 0x10
        ; run bios interrupt 0x10 for video output service         
        popa
        ret

printcr0:    
    cli     
        ; to clr the interrupts
    lgdt [GDT32.Pointer ] 
        ; Loads the gdt for 32 bit mode
    mov eax , cr0
    or eax , 0x1     ;
    mov cr0 , eax
        ;update CR0 to enter protect mode
    jmp GDT32.Code:PrintValueCR0

[ BITS 32  ]
;include files
%include "set_seg_register.nasm"
PrintValueCR0:    
    ; segment valus protected mode
    mov ax , GDT32.Data  
    ;AX has values for segments
    ;32 mode        
    ; Flag for print
    mov edx , cr0     
    mov ecx , 32             
    ; 32 bits reqd 
    mov ebx , 0xB8640        
    ; Display screen offset
.loop2:
    mov eax , 00000230h
    ;green 
    shl edx , 1              
    ; carry flag
    ;top bit
    adc eax , 0              
    ;for 0 or 1 in al
    mov [ebx ] , ax
    add ebx , 2
    dec ecx
    jnz .loop2
halt:
    cli
    hlt
    jmp halt
    
MSG_1 db "Hello world" , 0

times 510 - ($-$$) db 0 
dw 0xaa55