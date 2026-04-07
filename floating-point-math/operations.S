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

.global Cos
Cos:
	// Load the value in the xmm0 register into the memory stack
	movss %xmm0, -4(%rsp)
	// Push the value stored in the memory stack into the top of the FPU stack, and then do the operation
	flds -4(%rsp)	# the flds load single-precision (32bit) value while the fld loads double-precision value (64bit)
	fcos
	// Store the result into the memory stack then move it back to the xmm0 register
	fstps -4(%rsp)
	movss -4(%rsp), %xmm0
	ret

.global Sin
Sin:
	movss %xmm0, -4(%rsp)
	flds -4(%rsp)
	fsin
	fstps -4(%rsp)
	movss -4(%rsp), %xmm0
	ret

.global Tan
Tan:
	movss %xmm0, -4(%rsp)
	flds -4(%rsp)
	// the fptan instruction repalces the ST(0) register by the result and push one into the top of the FPU stack, so basically the value now
	// are in the ST(1) register
	fptan
	fld %st(1)
	fstps -4(%rsp)
	movss -4(%rsp), %xmm0
	ret
