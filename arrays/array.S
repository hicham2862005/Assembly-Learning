.section .note.GNU-stack,"",@progbits

// the .data section constains the variables and arrays initialized at compile-time and also global variables are declared here
.section .data
my_array:
	.long 10, 20, 30, 40, 50	# equivalent of int my_array[5] = {10,20,30,40,50} in C


// return the value in the array at the given index
.section .text
.global read_array
read_array:
	mov my_array(%rip, %rdi, 4), %eax	# this means read what are in my_array[EDI] where every item are 4-bytes (32bit) in size and mov it to EAX register, the RIP here refers to the address at where the first item of the array are located
	ret

// TODO: fix the invalid base/index addressing issue
