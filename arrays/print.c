#include<stdio.h>

int read_array(int index);

int main()
{
	int result = read_array(0);
	printf("%d\n",result);	// should be 10
	return 0;
}
