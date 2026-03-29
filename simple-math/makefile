objects = add.o print.o

add.o: add.S
	as add.S -o add.o

print.o: print.c
	gcc -c print.c -o print.o

build: $(objects)
	gcc $(objects) -o run
	rm -rf *.o
