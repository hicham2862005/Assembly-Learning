// this example involves the use of REP prefix for loop on a knowen size array/string that are stored in the memory and moving its content to another array/string
// the ESI (RSI in 64bit machines) containes the source address, the EDI (RDI) containes the Destination address and the EDX contains the lenght
// of the data that we gonna move

.section .note.GNU-stack,"",@progbits
.section .text

// move(dest, source, length)
.global move
move:
	mov %edx, %ecx	# mov the length, which is the 3rd argument to the ECX register, to be used as a counter
	rep movsb	# mov one byte from the address at the ESI to the address at the EDI for an ECX times
