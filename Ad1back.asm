SECTION .DATA
SECTION .TEXT
    GLOBAL Addition

Addition:
    ;mov eax, edi
    ;add eax, esi
    ;ret

    mov rax, rdi
    add rax, rsi
    ;mov ecx, eax

    ;mov ebx,1
    ;mov eax,4
    ;int 0x80
    mov rax, 1
    mov rdi, 1
    mov rsi, message
  	mov rdx, 13
    syscall

    ;system exit
    mov rax,60	;sys_exit
    xor rdi,rdi ; rdi set to 0
    syscall
		
message:
  db "Hello world", 10		
