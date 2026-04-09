objects = print.o move.o

move.o: move.S
	as move.S -o move.o

print.o: print.c
	gcc -c print.c -o print.o

build: $(objects)
	gcc $(objects) -o run
	rm -rf *.o
