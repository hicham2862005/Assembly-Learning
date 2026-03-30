#include<stdio.h>

int Add(int a, int b);
int Sub(int a, int b);
int Mul(int a, int b);
int Div_q(int a, int b);
int Div_r(int a, int b);

int main()
{
	int result = Div_q(20,30);
	printf("%d\n",result);
	return 0;
}
