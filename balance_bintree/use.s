	.file	"use.c"
	.section	.rodata
.LC0:
	.string	"%s!\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$32, %esp
	movl	%gs:20, %eax
	movl	%eax, 28(%esp)
	xorl	%eax, %eax
	leal	23(%esp), %eax
	movl	%eax, (%esp)
	call	gets
	movl	$.LC0, %eax
	leal	23(%esp), %edx
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	printf
	movl	$0, %eax
	movl	28(%esp), %edx
	xorl	%gs:20, %edx
	je	.L2
	call	__stack_chk_fail
.L2:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits
