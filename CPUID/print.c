#include<stdio.h>
#include<stdint.h>	// for uint8_t and uint16_t type

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
		uint32_t Max_leaf;
		char Vendor_ID_1[4];
		char Vendor_ID_2[4];
		char Vendor_ID_3[4];
	} Basic_CPUID_Information;
	struct {
		// EAX
		uint32_t Stepping_ID		: 4;
		uint32_t Model_ID		: 4;
		uint32_t Family_ID		: 4;
		uint32_t Processor_Type		: 2;
		uint32_t Reserved_1		: 2;
		uint32_t Extended_Model_ID	: 4;
		uint32_t Extended_Family_ID	: 8;
		uint32_t Reserved_2		: 4;
		// EBX
		uint32_t Brand_Index		: 8;
		uint32_t CLFLUSH_Line_Size	: 8;
		uint32_t APIC_ID_Space		: 8;
		uint32_t Initial_APIC_ID	: 8;
		// ECX
		uint32_t SSE3			: 1;
		uint32_t PCLMULQDQ		: 1;
		uint32_t DTES64			: 1;
		uint32_t MONITOR		: 1;
		uint32_t DS_CPL			: 1;
		uint32_t VMX			: 1;
		uint32_t SMX			: 1;
		uint32_t EIST			: 1;
		uint32_t TM2			: 1;
		uint32_t SSSE3			: 1;
		uint32_t L1_Context_ID		: 1;			// adaptive mode or shared mode
		uint32_t Debug_Interface	: 1;
		uint32_t FMA			: 1;
		uint32_t CMPXCHG16B		: 1;
		uint32_t XTRP_Update_Control	: 1;
		uint32_t Perf_Capabilities	: 1;
		uint32_t Reserved_3		: 1;
		uint32_t PCID			: 1;
		uint32_t DCA			: 1;
		uint32_t SSE4_1			: 1;
		uint32_t SSE4_2			: 1;
		uint32_t X2APIC			: 1;
		uint32_t MOVBE			: 1;
		uint32_t POPCNT			: 1;
		uint32_t TSC_Deadline		: 1;
		uint32_t AESNI			: 1;
		uint32_t XSAVE			: 1;
		uint32_t OSXSAVE		: 1;
		uint32_t AVX			: 1;
		uint32_t F16C			: 1;
		uint32_t RDRAND			: 1;
		uint32_t Not_Used		: 1;
		// EDX
		uint32_t FPU			: 1;
		uint32_t VME			: 1;
		uint32_t DE			: 1;
		uint32_t PSE			: 1;
		uint32_t TSC			: 1;
		uint32_t MSR			: 1;
		uint32_t PAE			: 1;
		uint32_t MCE			: 1;
		uint32_t CMPXCHG8B		: 1;
		uint32_t APIC			: 1;
		uint32_t Reserved_4		: 1;
		uint32_t SEP			: 1;
		uint32_t MTRR			: 1;
		uint32_t PGE			: 1;
		uint32_t MCA			: 1;
		uint32_t CMOV			: 1;
		uint32_t PAT			: 1;
		uint32_t PSE_36			: 1;
		uint32_t PSN			: 1;
		uint32_t CLFLUSH		: 1;
		uint32_t Reserved_5		: 1;
		uint32_t DS			: 1;
		uint32_t ACPI			: 1;
		uint32_t MMX			: 1;
		uint32_t FXSR			: 1;
		uint32_t SSE			: 1;
		uint32_t SSE2			: 1;
		uint32_t Self_Snoop		: 1;
		uint32_t HTT			: 1;
		uint32_t TM			: 1;
		uint32_t Reserved_6		: 1;
		uint32_t PBE			: 1;
	} Version_And_Features;
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
