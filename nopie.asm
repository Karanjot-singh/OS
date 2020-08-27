SECTION .BSS
	digitspace resb 100; reserve 100B to store the number as string
	digitspacepos resb 8 ; reserve 8bytes for 64bit register val to calc how far reached

	

SECTION .TEXT
    GLOBAL Addition

PrintNumber:
	;breaks the digit backwards
	mov rcx, digitspace ; digitspace at the beginning
	mov rbx, 10 ; new line chara
	mov [rcx], rbx ; mov rbx as a ptr into rbx
	inc rcx ; increment position
	mov[digitspacepos], rcx

PrintNumberLoop:
	;mod 10 approach inverted
	mov rdx, 0 ; rdx gets conactenated when div is used
	mov rbx, 10
	div rbx
	push rax
	;on division rdx stores the remainder part
	add rdx, 48 ; to add for ascii conversion to char

	mov rcx, [digitspacepos]; to increment pos
	mov [rcx], dl ; lower 8bytes of rdx 
	inc rcx
	mov [digitspacepos], rcx

	;Termination condition
	pop rax
	cmp rax,0
	jne PrintNumberLoop

PrintForward:
	 mov rcx, [digitspacepos]
	 mov rax,1
	 mov rdi,1
	 mov rsi, rcx
	 mov rdx, 1
	 syscall

	 mov rcx ,[digitspacepos]
	 dec rcx
	 mov [digitspacepos], rcx

	 cmp rcx, digitspace
	 jge PrintForward
	 ret

Addition:
    mov rax, rdi
    add rax, rsi

    call PrintNumber

    ;mov rax, 1
    ;mov rdi, 1

    ;mov rsi, message
  	;mov rdx, 13
    syscall

    ;system exit
    mov rax,60	;sys_exit
    xor rdi,rdi ; rdi set to 0
    syscall
		
message:
  db "Hello world", 10		
