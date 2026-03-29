.section .note.GNU-stack,"",@progbits
.section .text
.global Add

Add:
	#mov src, dst
	mov %edi, %eax   # move first argument into return register
	#means: eax = eax + esi
	add %esi, %eax   # add second argument
	ret
