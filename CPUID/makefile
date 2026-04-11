objects = cpuid.o print.o

cpuid.o: cpuid.S
	as cpuid.S -o cpuid.o

print.o: print.c
	gcc -c print.c -o print.o

build: $(objects)
	gcc $(objects) -o run
	rm -rf *.o
