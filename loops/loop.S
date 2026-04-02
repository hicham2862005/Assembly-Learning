.section .note.GNU-stack,"",@progbits
.section .text

.global Pow
Pow:
	mov %esi, %ecx	# usually the ECX register are used also for counters along side of using it as a general purpose register
	mov $1, %eax	# EAX contains one as initial value
Loop:
	cmp $0, %ecx
	je Finish	# jump if the %ecx is 0
	dec %ecx	# ECX = ECX - 1
	mul %edi	# EAX = EDI * EAX (EDI are our first argument)
	jmp Loop	# finish one cycle of the loop, go back to the start and do the same thing

Finish:
	ret
