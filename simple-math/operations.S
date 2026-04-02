.section .note.GNU-stack,"",@progbits
.section .text

.global Add
Add:
	#mov src, dst
	mov %edi, %eax   # move first argument into return register
	#means: eax = eax + esi
	add %esi, %eax   # add second argument
	ret

.global Sub
Sub:
	mov %edi, %eax
	sub %esi, %eax
	ret

.global Mul
Mul:
	mov %edi, %eax
	mov %esi, %ebx
	mul %ebx	# eax = edi * esi
	ret

.global Div_q
Div_q:
	mov %edi, %eax
	mov %esi, %ecx
	xor %edx, %edx	# clear the EDX register to prevent result errors
	div %ecx
	ret	# return the Quotient

.global Div_r
Div_r:
	mov %edi, %eax
	mov %esi, %ecx
	xor %edx, %edx
	div %ecx
	mov %edx, %eax
	ret	# return the Remainder
