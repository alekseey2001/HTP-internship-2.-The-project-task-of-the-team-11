/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#ifndef	_ProximityIndication_r9_H_
#define	_ProximityIndication_r9_H_


#include <asn_application.h>

/* Including external dependencies */
#include "ProximityIndication-r9-IEs.h"
#include <NULL.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum ProximityIndication_r9__criticalExtensions_PR {
	ProximityIndication_r9__criticalExtensions_PR_NOTHING,	/* No components present */
	ProximityIndication_r9__criticalExtensions_PR_c1,
	ProximityIndication_r9__criticalExtensions_PR_criticalExtensionsFuture
} ProximityIndication_r9__criticalExtensions_PR;
typedef enum ProximityIndication_r9__criticalExtensions__c1_PR {
	ProximityIndication_r9__criticalExtensions__c1_PR_NOTHING,	/* No components present */
	ProximityIndication_r9__criticalExtensions__c1_PR_proximityIndication_r9,
	ProximityIndication_r9__criticalExtensions__c1_PR_spare3,
	ProximityIndication_r9__criticalExtensions__c1_PR_spare2,
	ProximityIndication_r9__criticalExtensions__c1_PR_spare1
} ProximityIndication_r9__criticalExtensions__c1_PR;

/* ProximityIndication-r9 */
typedef struct ProximityIndication_r9 {
	struct ProximityIndication_r9__criticalExtensions {
		ProximityIndication_r9__criticalExtensions_PR present;
		union ProximityIndication_r9__criticalExtensions_u {
			struct ProximityIndication_r9__criticalExtensions__c1 {
				ProximityIndication_r9__criticalExtensions__c1_PR present;
				union ProximityIndication_r9__criticalExtensions__c1_u {
					ProximityIndication_r9_IEs_t	 proximityIndication_r9;
					NULL_t	 spare3;
					NULL_t	 spare2;
					NULL_t	 spare1;
				} choice;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} c1;
			struct ProximityIndication_r9__criticalExtensions__criticalExtensionsFuture {
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} criticalExtensionsFuture;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} criticalExtensions;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} ProximityIndication_r9_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_ProximityIndication_r9;
extern asn_SEQUENCE_specifics_t asn_SPC_ProximityIndication_r9_specs_1;
extern asn_TYPE_member_t asn_MBR_ProximityIndication_r9_1[1];

#ifdef __cplusplus
}
#endif

#endif	/* _ProximityIndication_r9_H_ */
#include <asn_internal.h>