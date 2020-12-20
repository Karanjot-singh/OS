;Source index is use as a pointer to the current character being read in a string instruction
org 0x7C00                      ; to inform NASM to start at address 0x7c00
bits 16                         ; To inform the assembler that this is 16 bit mode
start:
	cli                     ; clear all interrupts
	mov si, msg             ; Source index now points to Hello world
	mov ah, 0x0E            ; Informs that we wnt to print chars

.loop:	
	; instruction to load a string byte at DS:SI register
	lodsb                   ; Loads SI into AL and increments SI [next char] 

	or al, al               ; Checks if the loaded string ended by al==0?
	jz halt                 ; halts loop if al == 0 and hence end
	int 0x10                ; Else run bios interrupt 0x10 for video output service
	jmp .loop               ; loop continuation condition

halt:
	hlt

msg:	db " Hello World ",0;

							;Magic numbers for booting
times 510 - ( $ - $$ ) db 0 	; adds 0 to remaining 510 bytes
dw 0xAA55 					; To mark bootable
