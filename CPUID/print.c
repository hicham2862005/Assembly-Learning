#include<stdio.h>
#include<stdint.h>	// for uint8_t and uint16_t type

// this function are used to extract the CPUID Feature and display it in it's raw form
void GetFeature(uint16_t FeatureID, uint32_t *output);

// the Decoder Sturcture for extracting the features in a more clean way
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
	BASIC_CPUID_INFORMATION = 0				,	// 00H
	VERSION_AND_FEATURES					,	// 01H
	TLB_CACHE_PREFETCH_INFORMATION				,	// 02H
	PROCESSOR_SERIAL_NUMBER					,	// 03H
	DETERMINISTIC_CHACE_PARAMETERS				,	// 04H
	MONITOR_AND_WAIT_FEATURES				,	// 05H
	THERMAL_AND_POWER_MANAGEMENT_FEATURES			,	// 06H
	STRUCTURED_EXTENDED_FEATURES				,	// 07H
	RESERVED_1						,	// 08H
	DIRECT_CACHE_ACCESS_INFORMATION				,	// 09H
	ARCHITECTURAL_PERFORMANCE_MONITORING			,	// 0AH
	EXTENDED_TOPOLOGY					,	// 0BH
	RESERVED_2						,	// 0CH
	PROCESSOR_EXTENDED_STATE				,	// 0DH
	RESERVED_3						,	// 0EH
	INTEL_RDT_TECHNOLOGY_MONITORING				,	// 0FH
	INTEL_RDT_TECHNOLOGY_ALLOCATION				,	// 10H
	RESERVED_4						,	// 11H
	INTEL_SGX_CAPABILITY					,	// 12H
	RESERVED_5						,	// 13H
	INTEL_PT						,	// 14H
	TIME_STAMP_COUNTER_AND_NOMINAL_CORE_CRYSTAL_CLOCK	,	// 15H
	PROCESSOR_FREQUENCY_INFORMATION				,	// 16H
	SOC_VENDOR_ATTRIBUTE					,	// 17H
	DETERMINISTIC_ADDRESS_TRANSLATION_PARAMETERS		,	// 18H
	KEY_LOCKER						,	// 19H
	NATIVE_MODEL_ID_ENUMERATION				,	// 1AH
	PCONFIG_INFORMATION					,	// 1BH
	LAST_BRANCH_RECORD_INFORMATION				,	// 1CH
	TILE_INFORMATION					,	// 1DH
	TMUL_INFORMATION					,	// 1EH
	V2_EXTENDED_TOPOLOGY					,	// 1FH
	PROCESSOR_RESET_HISTORY_INFORMATION			,	// 20H
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
