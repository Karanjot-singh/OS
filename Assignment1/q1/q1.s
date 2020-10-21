	.file	"q1.c"
	.text
	.section	.rodata
.LC0:
	.string	","
.LC2:
	.string	"Student ID: %s | "
.LC3:
	.string	"Section: %s | "
.LC5:
	.string	"Average Marks:- %.2f \n"
	.text
	.globl	getData
	.type	getData, @function
getData:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	leaq	.LC0(%rip), %rsi
	movq	%rax, %rdi
	call	strtok@PLT
	movq	%rax, -8(%rbp)
	pxor	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	movl	$0, -12(%rbp)
	jmp	.L2
.L9:
	addl	$1, -12(%rbp)
	cmpl	$1, -12(%rbp)
	jne	.L3
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	pxor	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	jmp	.L4
.L3:
	cmpl	$2, -12(%rbp)
	jne	.L5
	movq	-8(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	pxor	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	jmp	.L4
.L5:
	cmpl	$3, -12(%rbp)
	jne	.L6
	cvtss2sd	-16(%rbp), %xmm2
	movsd	%xmm2, -32(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	atof@PLT
	addsd	-32(%rbp), %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	jmp	.L4
.L6:
	cmpl	$4, -12(%rbp)
	jne	.L7
	cvtss2sd	-16(%rbp), %xmm3
	movsd	%xmm3, -32(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	atof@PLT
	addsd	-32(%rbp), %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	jmp	.L4
.L7:
	cmpl	$5, -12(%rbp)
	jne	.L8
	cvtss2sd	-16(%rbp), %xmm4
	movsd	%xmm4, -32(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	atof@PLT
	addsd	-32(%rbp), %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
	jmp	.L4
.L8:
	cmpl	$6, -12(%rbp)
	jne	.L4
	cvtss2sd	-16(%rbp), %xmm5
	movsd	%xmm5, -32(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	atof@PLT
	addsd	-32(%rbp), %xmm0
	cvtsd2ss	%xmm0, %xmm0
	movss	%xmm0, -16(%rbp)
.L4:
	leaq	.LC0(%rip), %rsi
	movl	$0, %edi
	call	strtok@PLT
	movq	%rax, -8(%rbp)
.L2:
	cmpq	$0, -8(%rbp)
	jne	.L9
	movss	-16(%rbp), %xmm0
	movss	.LC4(%rip), %xmm1
	divss	%xmm1, %xmm0
	movss	%xmm0, -16(%rbp)
	cvtss2sd	-16(%rbp), %xmm0
	leaq	.LC5(%rip), %rdi
	movl	$1, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	getData, .-getData
	.section	.rodata
.LC6:
	.string	"Error in fork process"
.LC7:
	.string	"Child Process- Pid: %d \n"
.LC8:
	.string	"file.csv"
.LC9:
	.string	"Error "
.LC10:
	.string	"\nParent Process- Pid: %d \n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB7:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$4096, %rsp
	orq	$0, (%rsp)
	subq	$4096, %rsp
	orq	$0, (%rsp)
	subq	$2992, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	call	fork@PLT
	movl	%eax, -11136(%rbp)
	cmpl	$0, -11136(%rbp)
	jns	.L11
	leaq	.LC6(%rip), %rdi
	call	perror@PLT
	movl	$1, %eax
	jmp	.L36
.L11:
	cmpl	$0, -11136(%rbp)
	jne	.L13
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC7(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %esi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -11124(%rbp)
	cmpl	$0, -11124(%rbp)
	jns	.L14
	leaq	.LC9(%rip), %rdi
	call	perror@PLT
	movl	$-1, %eax
	jmp	.L36
.L14:
	leaq	-7008(%rbp), %rcx
	movl	-11124(%rbp), %eax
	movl	$6999, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movb	$0, -8(%rbp)
	movl	$0, -11172(%rbp)
	movl	$0, -11168(%rbp)
	movl	$0, -11164(%rbp)
	movb	$0, -11176(%rbp)
	movl	$0, -11160(%rbp)
	jmp	.L15
.L21:
	movl	-11160(%rbp), %eax
	cltq
	movzbl	-7008(%rbp,%rax), %eax
	cmpb	$10, %al
	jne	.L16
	addl	$1, -11172(%rbp)
	movl	-11164(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-7008(%rbp), %rcx
	movl	-11168(%rbp), %eax
	cltq
	addq	%rax, %rcx
	leaq	-11008(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncat@PLT
	leaq	-11176(%rbp), %rcx
	leaq	-11008(%rbp), %rax
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncat@PLT
	cmpl	$1, -11172(%rbp)
	jle	.L17
	leaq	-11008(%rbp), %rax
	movq	%rax, %rdi
	call	getData
.L17:
	movl	-11164(%rbp), %eax
	addl	$1, %eax
	addl	%eax, -11168(%rbp)
	movl	$0, -11164(%rbp)
	movb	$0, -11008(%rbp)
	jmp	.L18
.L16:
	movl	-11160(%rbp), %eax
	cltq
	movzbl	-7008(%rbp,%rax), %eax
	cmpb	$66, %al
	je	.L38
	addl	$1, -11164(%rbp)
.L18:
	addl	$1, -11160(%rbp)
.L15:
	cmpl	$6999, -11160(%rbp)
	jle	.L21
	jmp	.L20
.L38:
	nop
.L20:
	movl	-11124(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	$0, %edi
	call	exit@PLT
.L13:
	leaq	-11176(%rbp), %rcx
	movl	-11136(%rbp), %eax
	movl	$0, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	waitpid@PLT
	movl	%eax, -11132(%rbp)
	call	getpid@PLT
	movl	%eax, %esi
	leaq	.LC10(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %esi
	leaq	.LC8(%rip), %rdi
	movl	$0, %eax
	call	open@PLT
	movl	%eax, -11128(%rbp)
	cmpl	$0, -11128(%rbp)
	jns	.L22
	leaq	.LC9(%rip), %rdi
	call	perror@PLT
	movl	$-1, %eax
	jmp	.L36
.L22:
	leaq	-7008(%rbp), %rcx
	movl	-11128(%rbp), %eax
	movl	$6999, %edx
	movq	%rcx, %rsi
	movl	%eax, %edi
	call	read@PLT
	movb	$0, -8(%rbp)
	movl	$0, -11156(%rbp)
	movl	$0, -11152(%rbp)
	movl	$0, -11148(%rbp)
	movb	$0, -11177(%rbp)
	movl	$0, -11144(%rbp)
	jmp	.L23
.L28:
	movl	-11144(%rbp), %eax
	cltq
	movzbl	-7008(%rbp,%rax), %eax
	cmpb	$10, %al
	jne	.L24
	addl	$1, -11156(%rbp)
	movl	-11148(%rbp), %eax
	addl	$1, %eax
	addl	%eax, -11152(%rbp)
	movl	$0, -11148(%rbp)
	jmp	.L25
.L24:
	movl	-11144(%rbp), %eax
	cltq
	movzbl	-7008(%rbp,%rax), %eax
	cmpb	$66, %al
	je	.L39
	addl	$1, -11148(%rbp)
.L25:
	addl	$1, -11144(%rbp)
.L23:
	cmpl	$6999, -11144(%rbp)
	jle	.L28
	jmp	.L27
.L39:
	nop
.L27:
	movl	$7000, %eax
	subl	-11152(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-7008(%rbp), %rcx
	movl	-11152(%rbp), %eax
	cltq
	addq	%rax, %rcx
	leaq	-11008(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncat@PLT
	movl	$10, %edi
	call	putchar@PLT
	movl	$0, -11156(%rbp)
	movl	$0, -11152(%rbp)
	movl	$0, -11148(%rbp)
	movl	$0, -11140(%rbp)
	jmp	.L29
.L35:
	movl	-11140(%rbp), %eax
	cltq
	movzbl	-11008(%rbp,%rax), %eax
	cmpb	$10, %al
	jne	.L30
	addl	$1, -11156(%rbp)
	movl	-11148(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-11008(%rbp), %rcx
	movl	-11152(%rbp), %eax
	cltq
	addq	%rax, %rcx
	leaq	-11120(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncat@PLT
	leaq	-11177(%rbp), %rcx
	leaq	-11120(%rbp), %rax
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncat@PLT
	cmpl	$1, -11156(%rbp)
	jle	.L31
	leaq	-11120(%rbp), %rax
	movq	%rax, %rdi
	call	getData
.L31:
	movl	-11148(%rbp), %eax
	addl	$1, %eax
	addl	%eax, -11152(%rbp)
	movl	$0, -11148(%rbp)
	movb	$0, -11120(%rbp)
	jmp	.L32
.L30:
	movl	-11140(%rbp), %eax
	cltq
	movzbl	-11008(%rbp,%rax), %eax
	cmpb	$64, %al
	jne	.L33
	addl	$1, -11156(%rbp)
	movl	-11148(%rbp), %eax
	movslq	%eax, %rdx
	leaq	-11008(%rbp), %rcx
	movl	-11152(%rbp), %eax
	cltq
	addq	%rax, %rcx
	leaq	-11120(%rbp), %rax
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncat@PLT
	leaq	-11177(%rbp), %rcx
	leaq	-11120(%rbp), %rax
	movl	$1, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	strncat@PLT
	cmpl	$1, -11156(%rbp)
	jle	.L34
	leaq	-11120(%rbp), %rax
	movq	%rax, %rdi
	call	getData
.L34:
	movl	-11148(%rbp), %eax
	addl	$1, %eax
	addl	%eax, -11152(%rbp)
	movl	$0, -11148(%rbp)
	movb	$0, -11120(%rbp)
	jmp	.L32
.L33:
	addl	$1, -11148(%rbp)
.L32:
	addl	$1, -11140(%rbp)
.L29:
	cmpl	$3999, -11140(%rbp)
	jle	.L35
	movl	-11128(%rbp), %eax
	movl	%eax, %edi
	call	close@PLT
	movl	$0, %eax
.L36:
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L37
	call	__stack_chk_fail@PLT
.L37:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	main, .-main
	.section	.rodata
	.align 4
.LC4:
	.long	1082130432
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
