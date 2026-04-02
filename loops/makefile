objects = loop.o print.o

loop.o: loop.S
	as loop.S -o loop.o

print.o: print.c
	gcc -c print.c -o print.o

build: $(objects)
	gcc $(objects) -o run
	rm -rf *.o
