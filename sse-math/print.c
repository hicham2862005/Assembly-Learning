#include<stdio.h>

void SSE_Add(float *a, float *b, float *c);
void SSE_Sub(float *a, float *b, float *c);
void SSE_Mul(float *a, float *b, float *c);
void SSE_Div(float *a, float *b, float *c);


int main()
{
	float a[4], b[4], c[4];

	a[0] = 1.0; b[0] = 2.0;
	a[1] = 2.0; b[1] = 3.0;
	a[2] = 3.0; b[2] = 4.0;
	a[3] = 4.0; b[3] = 5.0;

	SSE_Add(a,b,c);

	for(int index = 0; index < 4; index++)
	{
		printf("C[%d] = %f\n",index,c[index]);
	}

	return 0;
}
