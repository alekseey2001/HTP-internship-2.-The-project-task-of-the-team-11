/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_RF_Parameters_v1310_H_
#define	_RF_Parameters_v1310_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <NativeInteger.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum RF_Parameters_v1310__eNB_RequestedParameters_r13__reducedIntNonContCombRequested_r13 {
	RF_Parameters_v1310__eNB_RequestedParameters_r13__reducedIntNonContCombRequested_r13_true	= 0
} e_RF_Parameters_v1310__eNB_RequestedParameters_r13__reducedIntNonContCombRequested_r13;
typedef enum RF_Parameters_v1310__eNB_RequestedParameters_r13__skipFallbackCombRequested_r13 {
	RF_Parameters_v1310__eNB_RequestedParameters_r13__skipFallbackCombRequested_r13_true	= 0
} e_RF_Parameters_v1310__eNB_RequestedParameters_r13__skipFallbackCombRequested_r13;
typedef enum RF_Parameters_v1310__maximumCCsRetrieval_r13 {
	RF_Parameters_v1310__maximumCCsRetrieval_r13_supported	= 0
} e_RF_Parameters_v1310__maximumCCsRetrieval_r13;
typedef enum RF_Parameters_v1310__skipFallbackCombinations_r13 {
	RF_Parameters_v1310__skipFallbackCombinations_r13_supported	= 0
} e_RF_Parameters_v1310__skipFallbackCombinations_r13;
typedef enum RF_Parameters_v1310__reducedIntNonContComb_r13 {
	RF_Parameters_v1310__reducedIntNonContComb_r13_supported	= 0
} e_RF_Parameters_v1310__reducedIntNonContComb_r13;

/* Forward declarations */
struct SupportedBandListEUTRA_v1310;
struct SupportedBandCombinationReduced_r13;

/* RF-Parameters-v1310 */
typedef struct RF_Parameters_v1310 {
	struct RF_Parameters_v1310__eNB_RequestedParameters_r13 {
		long	*reducedIntNonContCombRequested_r13	/* OPTIONAL */;
		long	*requestedCCsDL_r13	/* OPTIONAL */;
		long	*requestedCCsUL_r13	/* OPTIONAL */;
		long	*skipFallbackCombRequested_r13	/* OPTIONAL */;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} *eNB_RequestedParameters_r13;
	long	*maximumCCsRetrieval_r13	/* OPTIONAL */;
	long	*skipFallbackCombinations_r13	/* OPTIONAL */;
	long	*reducedIntNonContComb_r13	/* OPTIONAL */;
	struct SupportedBandListEUTRA_v1310	*supportedBandListEUTRA_v1310	/* OPTIONAL */;
	struct SupportedBandCombinationReduced_r13	*supportedBandCombinationReduced_r13	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RF_Parameters_v1310_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_reducedIntNonContCombRequested_r13_3;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_skipFallbackCombRequested_r13_7;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_maximumCCsRetrieval_r13_9;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_skipFallbackCombinations_r13_11;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_reducedIntNonContComb_r13_13;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_RF_Parameters_v1310;
extern asn_SEQUENCE_specifics_t asn_SPC_RF_Parameters_v1310_specs_1;
extern asn_TYPE_member_t asn_MBR_RF_Parameters_v1310_1[6];

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "SupportedBandListEUTRA-v1310.h"
#include "SupportedBandCombinationReduced-r13.h"

#endif	/* _RF_Parameters_v1310_H_ */
#include <asn_internal.h>