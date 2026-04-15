#include<stdio.h>
#include<stdint.h>	// for uint8_t and uint16_t type

// this function are used to extract the CPUID Feature and display it in it's raw form
void GetFeature(uint16_t FeatureID, uint32_t *output);

// this enum contians the FeatureID of each feature
typedef enum {
	BASIC_CPUID_INFORMATION_0 = 0,	// 00H
	BASIC_CPUID_INFORMATION_1,	// 01H
	BASIC_CPUID_INFORMATION_2,	// 02H
	BASIC_CPUID_INFORMATION_3,	// 03H
	DETERMINISTIC_CHACH_PARAMETERS,	// 04H
	MONITOR_WAIT,			// 05H -- Monitor Wait (Mwait)
} Features;

// this function extracts the feature and Decode it into a human readable form
void DescribeFeature(Features FeatureID)
{
	uint32_t output[4];		// output array for CPUID feature
	GetFeature(FeatureID, output);
	switch(FeatureID)
	{
		case BASIC_CPUID_INFORMATION_0:
			printf("Maximum Input Value for CPUID:		%d\n",output[0]);
			break;
		case BASIC_CPUID_INFORMATION_1:
			uint8_t SteppingID =	(output[0] & 0xf);
			uint8_t Model = 	(output[0] & (0xf << 4));
			uint8_t FamilyID =	(output[0] & (0xf << 8));
			uint8_t ProcessorType =	(output[0] & (0x3 << 12));
			printf("Stepping ID:				0x%02X\n",SteppingID);
			printf("Model:					0x%02X\n",Model);
			printf("Family ID:				0x%02X\n",FamilyID);
			printf("Processor Type:				0x%02X\n",ProcessorType);
			break;
		default:
			printf("Unsupported Feature ID\n");
			break;
	}
}

int main()
{
	DescribeFeature(BASIC_CPUID_INFORMATION_1);
	return 0;
}
