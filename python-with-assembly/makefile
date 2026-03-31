operations.o: operations.S
	as operations.S -o operations.o

build-lib: operations.o
	gcc -shared operations.o -o operations.so
	rm -rf *.o
