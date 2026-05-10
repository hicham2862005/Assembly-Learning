#include<stdio.h>
#include<stdint.h>	// for uint8_t, uint16_t and the uint32_t types

// this function are used to extract the CPUID Feature and display it in it's raw form
void GetFeature(uint16_t FeatureID, uint32_t *output);

// the Decoder Sturcture for extracting the features in a more clean way
typedef union {
	struct {
		uint32_t EAX;
		uint32_t EBX;
		uint32_t ECX;
		uint32_t EDX;
	} Raw;
	struct {
		// EAX
		uint32_t Max_leaf;
		// EBX
		char Vendor_ID_1[4];
		// ECX
		char Vendor_ID_2[4];
		// EDX
		char Vendor_ID_3[4];
	} Basic_CPUID_Information;
	struct {
		// EAX
		uint32_t Stepping_ID		: 4,
			 Model_ID		: 4,
			 Family_ID		: 4,
			 Processor_Type		: 2,
			 Reserved_1		: 2,
			 Extended_Model_ID	: 4,
			 Extended_Family_ID	: 8,
			 Reserved_2		: 4;
		// EBX
		uint32_t Brand_Index		: 8,
			 CLFLUSH_Line_Size	: 8,
			 APIC_ID_Space		: 8,
			 Initial_APIC_ID	: 8;
		// ECX
		uint32_t SSE3			: 1,
			 PCLMULQDQ		: 1,
			 DTES64			: 1,
			 MONITOR		: 1,
			 DS_CPL			: 1,
			 VMX			: 1,
			 SMX			: 1,
			 EIST			: 1,
			 TM2			: 1,
			 SSSE3			: 1,
			 L1_Context_ID		: 1,			// adaptive mode or shared mode
			 Debug_Interface	: 1,
			 FMA			: 1,
			 CMPXCHG16B		: 1,
			 XTRP_Update_Control	: 1,
			 Perf_Capabilities	: 1,
			 Reserved_3		: 1,
			 PCID			: 1,
			 DCA			: 1,
			 SSE4_1			: 1,
			 SSE4_2			: 1,
			 X2APIC			: 1,
			 MOVBE			: 1,
			 POPCNT			: 1,
			 TSC_Deadline		: 1,
			 AESNI			: 1,
			 XSAVE			: 1,
			 OSXSAVE		: 1,
			 AVX			: 1,
			 F16C			: 1,
			 RDRAND			: 1,
			 Not_Used		: 1;
		// EDX
		uint32_t FPU			: 1,
			 VME			: 1,
			 DE			: 1,
			 PSE			: 1,
			 TSC			: 1,
			 MSR			: 1,
			 PAE			: 1,
			 MCE			: 1,
			 CMPXCHG8B		: 1,
			 APIC			: 1,
			 Reserved_4		: 1,
			 SEP			: 1,
			 MTRR			: 1,
			 PGE			: 1,
			 MCA			: 1,
			 CMOV			: 1,
			 PAT			: 1,
			 PSE_36			: 1,
			 PSN			: 1,
			 CLFLUSH		: 1,
			 Reserved_5		: 1,
			 DS			: 1,
			 ACPI			: 1,
			 MMX			: 1,
			 FXSR			: 1,
			 SSE			: 1,
			 SSE2			: 1,
			 Self_Snoop		: 1,
			 HTT			: 1,
			 TM			: 1,
			 Reserved_6		: 1,
			 PBE			: 1;
	} Version_And_Features;
	struct {
		// EAX
		uint32_t Reserved_1		: 8,
			 Descriptor_1		: 8,
			 Descriptor_2		: 8,
			 Descriptor_3		: 8;
		// EBX
		uint32_t Descriptor_4		: 8,
			 Descriptor_5		: 8,
			 Descriptor_6		: 8,
			 Descriptor_7		: 8;
		// ECX
                uint32_t Descriptor_8           : 8,
                	 Descriptor_9           : 8,
                	 Descriptor_10          : 8,
                	 Descriptor_11          : 8;
		// EDX
		uint32_t Descriptor_12          : 8,
                	 Descriptor_13          : 8,
                	 Descriptor_14          : 8,
                	 Descriptor_15          : 8;
	} TLB_Cache_Prefetch_Information;
} CPUID_Decode;


// this enum contians the FeatureID of each feature
typedef enum {
	BASIC_CPUID_INFORMATION = 0				,	// 	 00H
	VERSION_AND_FEATURES					,	// 	 01H
	TLB_CACHE_PREFETCH_INFORMATION				,	// 	 02H
	PROCESSOR_SERIAL_NUMBER					,	// 	 03H
	DETERMINISTIC_CHACE_PARAMETERS				,	// 	 04H
	MONITOR_AND_WAIT_FEATURES				,	// 	 05H
	THERMAL_AND_POWER_MANAGEMENT_FEATURES			,	// 	 06H
	STRUCTURED_EXTENDED_FEATURES				,	// 	 07H
	RESERVED_1						,	// 	 08H
	DIRECT_CACHE_ACCESS_INFORMATION				,	// 	 09H
	ARCHITECTURAL_PERFORMANCE_MONITORING			,	// 	 0AH
	EXTENDED_TOPOLOGY					,	// 	 0BH
	RESERVED_2						,	// 	 0CH
	PROCESSOR_EXTENDED_STATE				,	// 	 0DH
	RESERVED_3						,	// 	 0EH
	INTEL_RDT_TECHNOLOGY_MONITORING				,	// 	 0FH
	INTEL_RDT_TECHNOLOGY_ALLOCATION				,	// 	 10H
	RESERVED_4						,	// 	 11H
	INTEL_SGX_CAPABILITY					,	// 	 12H
	RESERVED_5						,	// 	 13H
	INTEL_PT						,	// 	 14H
	TIME_STAMP_COUNTER_AND_NOMINAL_CORE_CRYSTAL_CLOCK	,	// 	 15H
	PROCESSOR_FREQUENCY_INFORMATION				,	// 	 16H
	SOC_VENDOR_ATTRIBUTE					,	// 	 17H
	DETERMINISTIC_ADDRESS_TRANSLATION_PARAMETERS		,	// 	 18H
	KEY_LOCKER						,	// 	 19H
	NATIVE_MODEL_ID_ENUMERATION				,	// 	 1AH
	PCONFIG_INFORMATION					,	// 	 1BH
	LAST_BRANCH_RECORD_INFORMATION				,	// 	 1CH
	TILE_INFORMATION					,	// 	 1DH
	TMUL_INFORMATION					,	// 	 1EH
	V2_EXTENDED_TOPOLOGY					,	// 	 1FH
	PROCESSOR_RESET_HISTORY_INFORMATION			,	// 	 20H
	UNIMPLEMENTED						,	// 	 21H
	RESERVED_6						,	//  	 22H
	ARCHITECTURAL_PERFORMANCE_MONITORING_EXTENDED		,	// 	 23H
	CONVERGED_VECTOR_ISA					,	// 	 24H
	INTEL_RDT_ASYMMETRIC_MONITORING	= 0x27			,	// 	 27H
	INTEL_RDT_ASYMMETRIC_ALLOCATION				,	// 	 28H
	MAX_INPUT_VALUE_FOR_EXTENDED_CPUID = (0x8 << 7)		,	// 80000000H
	EXTENDED_PROCESSOR_SIGNATURE_AND_FEATURE_BITS		,	// 80000001H
	PROCESSOR_BRAND_STRING_0_TO_15				,	// 80000002H
	PROCESSOR_BRAND_STRING_16_TO_31                         ,       // 80000003H
	PROCESSOR_BRAND_STRING_32_TO_47                         ,       // 80000004H
	RESERVED_7						,	// 80000005H
	EXTENDED_FUNCTION_CPUID_INFORMATION			,	// 80000006H
	EXTENDED_FUNCTION_CPUID_INFORMATION_1                   ,       // 80000007H
	EXTENDED_FUNCTION_CPUID_INFORMATION_2                   ,       // 80000008H
} Features;

// this function extracts the feature and Decode it into a human readable form
void DescribeFeature(Features FeatureID)
{
	uint32_t output[4];		// output array for CPUID feature
	GetFeature(FeatureID, output);
	switch(FeatureID)
	{
		case RESERVED_1:
		case RESERVED_2:
		case RESERVED_3:
		case RESERVED_4:
		case RESERVED_5:
		case RESERVED_6:
		case RESERVED_7:
			printf("Reserved Feature ID\n");
			break;
		case UNIMPLEMENTED:
			printf("Unimplemented Feature ID");
		default:
			printf("Unsupported Feature ID\n");
			break;
	}
}

int main()
{
	DescribeFeature(RESERVED_1);
	return 0;
}
