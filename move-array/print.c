#include<stdio.h>

// basically at the assembly level we dont care about the type of data at the source/dest so we made the generic type to accept any thing
void move(void *dest, void *src, int lenght);

int main()
{
	char src[12] = {'h','e','l','l','o',' ','w','o','r','l','d','\0'};
	char dest[12];

	move((void *)dest, (void *)src, 12);

	printf("%s\n",dest);

	return 0;
}
