#include<stdio.h>

float Add(float a, float b);
float Sub(float a, float b);
float Mul(float a, float b);
float Div(float a, float b);

int main()
{
	float result = Div(10.0,20.0);
	printf("%f\n",result);
	return 0;
}
