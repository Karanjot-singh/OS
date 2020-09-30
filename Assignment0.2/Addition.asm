SECTION .DATA
SECTION .TEXT
    GLOBAL Addition

Addition:

    mov rax, rdi ; First argument received in rdi and moved to rax
    add rax, rsi ; Second argument received from rsi added to rax
    ret ; The sum stored in rax is returned to the C program.
