	.file	"cast_oper.cpp"
	.section	.rodata
.LC0:
	.string	"test %d   %u \n"
.LC1:
	.string	"a+b %u  %d \n"
.LC2:
	.string	"a+b/2 %u %d \n"
.LC3:
	.string	" -1/2 = %u \n "
.LC4:
	.string	" -1/c = %u \n "
.LC5:
	.string	" a/c = %u \n "
	.align 4
.LC6:
	.string	"test %d (((0 * 2-1) + 0)/(2-1 + 1))= %u \n"
	.align 4
.LC7:
	.string	"test %d (((FrmLossValueAvg * 2-1) + 0)/(2-1 + 1))=  %u \n"
	.text
.globl _Z7test_u4v
	.type	_Z7test_u4v, @function
_Z7test_u4v:
.LFB0:
	.cfi_startproc
	.cfi_personality 0x0,__gxx_personality_v0
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$72, %esp
	movl	$0, -32(%ebp)
	movw	$2, -26(%ebp)
	movl	$0, -24(%ebp)
	movzwl	-26(%ebp), %eax
	imull	-32(%ebp), %eax
	addl	-24(%ebp), %eax
	subl	$1, %eax
	movzwl	-26(%ebp), %edx
	movl	%edx, -44(%ebp)
	movl	$0, %edx
	divl	-44(%ebp)
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$29, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$-1, -20(%ebp)
	movl	$0, -16(%ebp)
	movl	$2, -12(%ebp)
	movl	-16(%ebp), %eax
	movl	%eax, %edx
	addl	-20(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	-20(%ebp), %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	movl	-16(%ebp), %eax
	addl	-20(%ebp), %eax
	movl	%eax, %edx
	shrl	%edx
	movl	-16(%ebp), %eax
	addl	-20(%ebp), %eax
	shrl	%eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$0, 4(%esp)
	movl	$.LC3, (%esp)
	call	printf
	movl	$-1, %eax
	movl	%eax, %edx
	sarl	$31, %edx
	idivl	-12(%ebp)
	movl	%eax, 4(%esp)
	movl	$.LC4, (%esp)
	call	printf
	movl	-12(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	-20(%ebp), %eax
	movl	$0, %edx
	divl	-44(%ebp)
	movl	%eax, 4(%esp)
	movl	$.LC5, (%esp)
	call	printf
	movl	$0, -32(%ebp)
	movl	$0, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$47, 4(%esp)
	movl	$.LC6, (%esp)
	call	printf
	movl	$0, -32(%ebp)
	movl	-32(%ebp), %eax
	addl	%eax, %eax
	subl	$2, %eax
	shrl	%eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$51, 4(%esp)
	movl	$.LC7, (%esp)
	call	printf
	movl	$0, -32(%ebp)
	movzwl	-26(%ebp), %eax
	imull	-32(%ebp), %eax
	subl	$1, %eax
	shrl	%eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$55, 4(%esp)
	movl	$.LC7, (%esp)
	call	printf
	movl	$0, -32(%ebp)
	movzwl	-26(%ebp), %eax
	imull	-32(%ebp), %eax
	subl	$1, %eax
	shrl	%eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$59, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, -32(%ebp)
	movl	-32(%ebp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	shrl	%eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$63, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, -32(%ebp)
	movl	-32(%ebp), %eax
	addl	%eax, %eax
	subl	$1, %eax
	shrl	%eax
	movl	%eax, -32(%ebp)
	movl	-32(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	$67, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	_Z7test_u4v, .-_Z7test_u4v
	.ident	"GCC: (GNU) 4.4.7 20120313 (Red Hat 4.4.7-17)"
	.section	.note.GNU-stack,"",@progbits
