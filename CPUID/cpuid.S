// the return of those functions are an array of 128bit spilted into 4 parts ordered as Follows |EAX|EBX|ECX|EDX|

.section .note.GNU-stack,"",@progbits
.section .text

// GetFeature(featureId, *output);
.global GetFeature
GetFeature:
	mov %edi, %eax		# load featureId into EAX register
	cpuid
	mov %eax, (%rsi)	# load EAX to the first part of the output array
	mov %ebx, 4(%rsi)	# load EBX to the second part
	mov %ecx, 8(%rsi)
	mov %edx, 12(%rsi)
	ret
