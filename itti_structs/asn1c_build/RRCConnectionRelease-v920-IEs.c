/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "RRCConnectionRelease-v920-IEs.h"

static asn_oer_constraints_t asn_OER_type_cellInfoList_r9_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_cellInfoList_r9_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED | APC_EXTENSIBLE,  2,  2,  0,  2 }	/* (0..2,...) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_cellInfoList_r9_2[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct RRCConnectionRelease_v920_IEs__cellInfoList_r9, choice.geran_r9),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CellInfoListGERAN_r9,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"geran-r9"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RRCConnectionRelease_v920_IEs__cellInfoList_r9, choice.utra_FDD_r9),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CellInfoListUTRA_FDD_r9,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"utra-FDD-r9"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RRCConnectionRelease_v920_IEs__cellInfoList_r9, choice.utra_TDD_r9),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CellInfoListUTRA_TDD_r9,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"utra-TDD-r9"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct RRCConnectionRelease_v920_IEs__cellInfoList_r9, choice.utra_TDD_r10),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CellInfoListUTRA_TDD_r10,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"utra-TDD-r10"
		},
};
static const asn_TYPE_tag2member_t asn_MAP_cellInfoList_r9_tag2el_2[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* geran-r9 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* utra-FDD-r9 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* utra-TDD-r9 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* utra-TDD-r10 */
};
static asn_CHOICE_specifics_t asn_SPC_cellInfoList_r9_specs_2 = {
	sizeof(struct RRCConnectionRelease_v920_IEs__cellInfoList_r9),
	offsetof(struct RRCConnectionRelease_v920_IEs__cellInfoList_r9, _asn_ctx),
	offsetof(struct RRCConnectionRelease_v920_IEs__cellInfoList_r9, present),
	sizeof(((struct RRCConnectionRelease_v920_IEs__cellInfoList_r9 *)0)->present),
	asn_MAP_cellInfoList_r9_tag2el_2,
	4,	/* Count of tags in the map */
	0, 0,
	3	/* Extensions start */
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_cellInfoList_r9_2 = {
	"cellInfoList-r9",
	"cellInfoList-r9",
	&asn_OP_CHOICE,
	0,	/* No effective tags (pointer) */
	0,	/* No effective tags (count) */
	0,	/* No tags (pointer) */
	0,	/* No tags (count) */
	{ &asn_OER_type_cellInfoList_r9_constr_2, &asn_PER_type_cellInfoList_r9_constr_2, CHOICE_constraint },
	asn_MBR_cellInfoList_r9_2,
	4,	/* Elements count */
	&asn_SPC_cellInfoList_r9_specs_2	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_RRCConnectionRelease_v920_IEs_1[] = {
	{ ATF_POINTER, 2, offsetof(struct RRCConnectionRelease_v920_IEs, cellInfoList_r9),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		+1,	/* EXPLICIT tag at current level */
		&asn_DEF_cellInfoList_r9_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"cellInfoList-r9"
		},
	{ ATF_POINTER, 1, offsetof(struct RRCConnectionRelease_v920_IEs, nonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RRCConnectionRelease_v1020_IEs,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"nonCriticalExtension"
		},
};
static const int asn_MAP_RRCConnectionRelease_v920_IEs_oms_1[] = { 0, 1 };
static const ber_tlv_tag_t asn_DEF_RRCConnectionRelease_v920_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_RRCConnectionRelease_v920_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* cellInfoList-r9 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* nonCriticalExtension */
};
asn_SEQUENCE_specifics_t asn_SPC_RRCConnectionRelease_v920_IEs_specs_1 = {
	sizeof(struct RRCConnectionRelease_v920_IEs),
	offsetof(struct RRCConnectionRelease_v920_IEs, _asn_ctx),
	asn_MAP_RRCConnectionRelease_v920_IEs_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_RRCConnectionRelease_v920_IEs_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_RRCConnectionRelease_v920_IEs = {
	"RRCConnectionRelease-v920-IEs",
	"RRCConnectionRelease-v920-IEs",
	&asn_OP_SEQUENCE,
	asn_DEF_RRCConnectionRelease_v920_IEs_tags_1,
	sizeof(asn_DEF_RRCConnectionRelease_v920_IEs_tags_1)
		/sizeof(asn_DEF_RRCConnectionRelease_v920_IEs_tags_1[0]), /* 1 */
	asn_DEF_RRCConnectionRelease_v920_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_RRCConnectionRelease_v920_IEs_tags_1)
		/sizeof(asn_DEF_RRCConnectionRelease_v920_IEs_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_RRCConnectionRelease_v920_IEs_1,
	2,	/* Elements count */
	&asn_SPC_RRCConnectionRelease_v920_IEs_specs_1	/* Additional specs */
};
