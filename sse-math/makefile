objects = operations.o print.o

operations.o: operations.S
	as operations.S -o operations.o

print.o: print.c
	gcc -c print.c -o print.o

build: $(objects)
	gcc $(objects) -o run
	rm -rf *.o
