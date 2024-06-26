/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_RSTD_InterFreqInfo_r10_H_
#define	_RSTD_InterFreqInfo_r10_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ARFCN-ValueEUTRA.h"
#include <NativeInteger.h>
#include "ARFCN-ValueEUTRA-v9e0.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* RSTD-InterFreqInfo-r10 */
typedef struct RSTD_InterFreqInfo_r10 {
	ARFCN_ValueEUTRA_t	 carrierFreq_r10;
	long	 measPRS_Offset_r10;
	/*
	 * This type is extensible,
	 * possible extensions are below.
	 */
	ARFCN_ValueEUTRA_v9e0_t	*carrierFreq_v1090	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} RSTD_InterFreqInfo_r10_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_RSTD_InterFreqInfo_r10;
extern asn_SEQUENCE_specifics_t asn_SPC_RSTD_InterFreqInfo_r10_specs_1;
extern asn_TYPE_member_t asn_MBR_RSTD_InterFreqInfo_r10_1[3];

#ifdef __cplusplus
}
#endif

#endif	/* _RSTD_InterFreqInfo_r10_H_ */
#include <asn_internal.h>
