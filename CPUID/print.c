#include<stdio.h>
#include<stdint.h>	// for uint8_t and uint16_t type

// this function are used to extract the CPUID Feature and display it in it's raw form
void GetFeature(uint16_t FeatureID, uint32_t *output);

/*
 note: you could use something like this (example) for extracting each region of the CPUID output

	union vmx_exit_reason {
        struct {
                u32     basic                   : 16;
                u32     reserved16              : 1;
                u32     reserved17              : 1;
                u32     reserved18              : 1;
                u32     reserved19              : 1;
                u32     reserved20              : 1;
                u32     reserved21              : 1;
                u32     reserved22              : 1;
                u32     reserved23              : 1;
                u32     reserved24              : 1;
                u32     reserved25              : 1;
                u32     bus_lock_detected       : 1;
                u32     enclave_mode            : 1;
                u32     smi_pending_mtf         : 1;
                u32     smi_from_vmx_root       : 1;
                u32     reserved30              : 1;
                u32     failed_vmentry          : 1;
        };
        u32 full;
	};

from the "Linux Kernel" : "/arch/x86/kvm/vmx/common.h"
*/

typedef union {
	struct Raw {
		uint32_t EAX;
		uint32_t EBX;
		uint32_t ECX;
		uint32_t EDX;
	};
} CPUID_Decode;


// this enum contians the FeatureID of each feature
typedef enum {
	BASIC_CPUID_INFORMATION_0 = 0,	// 00H
	BASIC_CPUID_INFORMATION_1,	// 01H
	BASIC_CPUID_INFORMATION_2,	// 02H
	BASIC_CPUID_INFORMATION_3,	// 03H
	DETERMINISTIC_CHACE_PARAMETERS,	// 04H
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
			uint32_t temp = output[2];
			output[2] = output[3];
			output[3] = temp;
			printf("Vendor ID String:			%s\n",(((char *) output) + 4));
			break;
		case BASIC_CPUID_INFORMATION_1:
			uint8_t SteppingID =	(output[0] & 0xf);
			uint8_t Model = 	(output[0] >> 4) & 0xf;
			uint8_t FamilyID =	(output[0] >> 8) & 0xf;
			uint8_t ProcessorType =	(output[0] >> 12) & 0x3;
			printf("Stepping ID:				%d\n",SteppingID);
			printf("Model:					%d\n",Model);
			printf("Family ID:				%d\n",FamilyID);
			printf("Processor Type:				%d\n",ProcessorType);
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
