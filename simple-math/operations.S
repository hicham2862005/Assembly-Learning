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
	div %esi, %eax
	ret	# return the Quotient

.global Div_r
Div_r:
	mov %edi, %eax
	div %esi, %eax
	mov %edx, %eax
	ret	# return the Remainder
