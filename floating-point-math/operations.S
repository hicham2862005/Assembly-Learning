.section .note.GNU-stack,"",@progbits
.section .text

.global Add
Add:
	// xmm0 = xmm0 + xmm1
	addss %xmm1, %xmm0
	ret

.global Sub
Sub:
	// xmm0 = xmm0 - xmm1
	subss %xmm1, %xmm0
	ret

.global Mul
Mul:
	// xmm0 = xmm0 * xmm1
	mulss %xmm1, %xmm0
	ret

.global Div
Div:
	// xmm0 = xmm0 / xmm1
	divss %xmm1, %xmm0
	ret
