	.file	"002_example.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB23:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_def_cfa_offset 32
	movl	$0, 12(%rsp)
	movl	12(%rsp), %eax
	cmpl	$-1, %eax
	je	.L2
	.p2align 4,,10
	.p2align 3
.L3:
	movl	12(%rsp), %eax
	addl	$1, %eax
	movl	%eax, 12(%rsp)
	movl	12(%rsp), %eax
	cmpl	$-1, %eax
	jne	.L3
.L2:
	leaq	.LC0(%rip), %rsi
	movl	$5, %edx
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk@PLT
	xorl	%eax, %eax
	addq	$24, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE23:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
