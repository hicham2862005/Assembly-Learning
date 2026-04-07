#include<stdio.h>

float Add(float a, float b);
float Sub(float a, float b);
float Mul(float a, float b);
float Div(float a, float b);
// in those operations below "a" are considered to be in "radians"
float Cos(float a);
float Sin(float a);
float Tan(float a);


int main()
{
	float result = Tan(30);
	printf("%f\n",result);
	return 0;
}
