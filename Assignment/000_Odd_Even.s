	.file	"000_Odd_Even.c"
	.text
	.comm	num1,4,4
	.comm	rem,4,4
	.section	.rodata
.LC0:
	.string	"Enter a number:"
.LC1:
	.string	"%d"
.LC2:
	.string	"Number %d is positive even\n"
.LC3:
	.string	"Number %d is negative  even\n"
.LC4:
	.string	"Number %d is negative odd\n"
.LC5:
	.string	"Number %d is positive odd\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	leaq	num1(%rip), %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	num1(%rip), %eax
	cltd
	shrl	$31, %edx
	addl	%edx, %eax
	andl	$1, %eax
	subl	%edx, %eax
	movl	%eax, rem(%rip)
	movl	rem(%rip), %eax
	testl	%eax, %eax
	jne	.L2
	movl	num1(%rip), %eax
	testl	%eax, %eax
	jle	.L3
	movl	num1(%rip), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L5
.L3:
	movl	num1(%rip), %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L5
.L2:
	movl	num1(%rip), %eax
	testl	%eax, %eax
	jns	.L6
	movl	num1(%rip), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	jmp	.L5
.L6:
	movl	num1(%rip), %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
.L5:
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
