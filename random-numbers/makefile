objects = random.o print.o

random.o: random.S
	as random.S -o random.o

print.o: print.c
	gcc -c print.c -o print.o

build: $(objects)
	gcc $(objects) -o run
	rm -rf *.o
