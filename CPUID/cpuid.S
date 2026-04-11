// the return of those functions are an array of 128bit spilted into 4 parts ordered as Follows |EAX|EBX|ECX|EDX|

.section .note.GNU-stack,"",@progbits
.section .text

// this function uses the EAX only to request the CPU feature
// GetFeature1(featureId, *output);
.global GetFeature1
GetFeature1:
	mov %edi, %eax		# load featureId into EAX register
	cpuid
	mov %eax, (%rsi)	# load EAX to the first part of the output array
	mov %ebx, 4(%rsi)	# load EBX to the second part
	mov %ecx, 8(%rsi)
	mov %edx, 12(%rsi)
	ret
