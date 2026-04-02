// This Example uses a feature in intel cpus, which called SSE (Streaming SIMD Extensions), which enables performing SIMD (Single Instruction
// Multiple Data) on 128bit Data Registers containing 4 Single presicion floating point numbers (32bit for each), which are equivalent to
// "float" type in C, which speeds up the processing of data

.section .note.GNU-stack,"",@progbits
.section .text

// NOTE: this code done below, gonna work only in 64bit hardware due to its use of RDI, RSI, RDX registers to store the 64bit memory addresses
// in case if you want to use it with 32bit machine, change the RDI, RSI, RDX to EDI, ESI, EDX respectively

.global SSE_Add
SSE_Add:
	movups (%rdi), %xmm0	# we load the first 128bit content of the array that its address are stored in EDI (first argument)
	movups (%rsi), %xmm1	# same as the first but with the second argument
	addps %xmm1, %xmm0	# XMM0 = XMM0 + XMM1  (vector addition)
	movups %xmm0, (%rdx)	# move the XMM0 content to the memory address stored in EDX (third argument)
	ret			# return the result (XMM0) as float array (we got output in the third argument)


.global SSE_Sub
SSE_Sub:
	movups (%rdi), %xmm0
	movups (%rsi), %xmm1
	subps %xmm1, %xmm0	# XMM0 = XMM0 - XMM1
	movups %xmm0, (%rdx)
	ret


.global SSE_Mul
SSE_Mul:
	movups (%rdi), %xmm0
	movups (%rsi), %xmm1
	mulps %xmm1, %xmm0	# XMM0 = XMM0 * XMM1
	movups %xmm0, (%rdx)
	ret


.global SSE_Div
SSE_Div:
	movups (%rdi), %xmm0
	movups (%rsi), %xmm1
	divps %xmm1, %xmm0	# XMM0 = XMM0 / XMM1
	movups %xmm0, (%rdx)
	ret
