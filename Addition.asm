SECTION .DATA
SECTION .TEXT
    GLOBAL Addition

Addition:
    mov rax, rdi
    add rax, rsi

    mov rax, 1
    mov rdi, 1
    
    ;mov rsi, message
  	;mov rdx, 13
    syscall

    ;system exit
    mov rax,60	;sys_exit
    xor rdi,rdi ; rdi set to 0
    syscall
		
message:
  db "Hello world", 10		
