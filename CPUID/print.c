#include<stdio.h>

void GetFeature1(int FeatureID, int *output);

int main()
{
	int output[4];
	GetFeature1(11, output);

	printf("EAX: %d\n", output[0]);
	printf("EBX: %d\n", output[1]);
	printf("ECX: %d\n", output[2]);
	printf("EDX: %d\n", output[3]);
	return 0;
}
