/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_CSI_RS_Config_NZP_v1430_H_
#define	_CSI_RS_Config_NZP_v1430_H_


#include <asn_application.h>

/* Including external dependencies */
#include "NZP-TransmissionComb-r14.h"
#include "NZP-FrequencyDensity-r14.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* CSI-RS-Config-NZP-v1430 */
typedef struct CSI_RS_Config_NZP_v1430 {
	NZP_TransmissionComb_r14_t	*transmissionComb_r14	/* OPTIONAL */;
	NZP_FrequencyDensity_r14_t	*frequencyDensity_r14	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} CSI_RS_Config_NZP_v1430_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_CSI_RS_Config_NZP_v1430;
extern asn_SEQUENCE_specifics_t asn_SPC_CSI_RS_Config_NZP_v1430_specs_1;
extern asn_TYPE_member_t asn_MBR_CSI_RS_Config_NZP_v1430_1[2];

#ifdef __cplusplus
}
#endif

#endif	/* _CSI_RS_Config_NZP_v1430_H_ */
#include <asn_internal.h>