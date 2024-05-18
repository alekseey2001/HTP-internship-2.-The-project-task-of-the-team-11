/*
 * Generated by asn1c-0.9.29 (http://lionet.info/asn1c)
 * From ASN.1 module "NBIOT-RRC-Definitions"
 * 	found in "lte-rrc-14.7.0.asn1"
 * 	`asn1c -gen-PER -fcompound-names -no-gen-example`
 */

#include "UE-RadioPagingInfo-NB-r13.h"

/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
/*
 * This type is implemented using NativeEnumerated,
 * so here we adjust the DEF accordingly.
 */
static asn_oer_constraints_t asn_OER_type_ue_Category_NB_r13_constr_2 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_ue_Category_NB_r13_constr_2 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_oer_constraints_t asn_OER_type_multiCarrierPaging_r14_constr_5 CC_NOTUSED = {
	{ 0, 0 },
	-1};
static asn_per_constraints_t asn_PER_type_multiCarrierPaging_r14_constr_5 CC_NOTUSED = {
	{ APC_CONSTRAINED,	 0,  0,  0,  0 }	/* (0..0) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static const asn_INTEGER_enum_map_t asn_MAP_ue_Category_NB_r13_value2enum_2[] = {
	{ 0,	3,	"nb1" }
};
static const unsigned int asn_MAP_ue_Category_NB_r13_enum2value_2[] = {
	0	/* nb1(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_ue_Category_NB_r13_specs_2 = {
	asn_MAP_ue_Category_NB_r13_value2enum_2,	/* "tag" => N; sorted by tag */
	asn_MAP_ue_Category_NB_r13_enum2value_2,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_ue_Category_NB_r13_tags_2[] = {
	(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_ue_Category_NB_r13_2 = {
	"ue-Category-NB-r13",
	"ue-Category-NB-r13",
	&asn_OP_NativeEnumerated,
	asn_DEF_ue_Category_NB_r13_tags_2,
	sizeof(asn_DEF_ue_Category_NB_r13_tags_2)
		/sizeof(asn_DEF_ue_Category_NB_r13_tags_2[0]) - 1, /* 1 */
	asn_DEF_ue_Category_NB_r13_tags_2,	/* Same as above */
	sizeof(asn_DEF_ue_Category_NB_r13_tags_2)
		/sizeof(asn_DEF_ue_Category_NB_r13_tags_2[0]), /* 2 */
	{ &asn_OER_type_ue_Category_NB_r13_constr_2, &asn_PER_type_ue_Category_NB_r13_constr_2, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_ue_Category_NB_r13_specs_2	/* Additional specs */
};

static const asn_INTEGER_enum_map_t asn_MAP_multiCarrierPaging_r14_value2enum_5[] = {
	{ 0,	4,	"true" }
};
static const unsigned int asn_MAP_multiCarrierPaging_r14_enum2value_5[] = {
	0	/* true(0) */
};
static const asn_INTEGER_specifics_t asn_SPC_multiCarrierPaging_r14_specs_5 = {
	asn_MAP_multiCarrierPaging_r14_value2enum_5,	/* "tag" => N; sorted by tag */
	asn_MAP_multiCarrierPaging_r14_enum2value_5,	/* N => "tag"; sorted by N */
	1,	/* Number of elements in the maps */
	0,	/* Enumeration is not extensible */
	1,	/* Strict enumeration */
	0,	/* Native long size */
	0
};
static const ber_tlv_tag_t asn_DEF_multiCarrierPaging_r14_tags_5[] = {
	(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
	(ASN_TAG_CLASS_UNIVERSAL | (10 << 2))
};
static /* Use -fall-defs-global to expose */
asn_TYPE_descriptor_t asn_DEF_multiCarrierPaging_r14_5 = {
	"multiCarrierPaging-r14",
	"multiCarrierPaging-r14",
	&asn_OP_NativeEnumerated,
	asn_DEF_multiCarrierPaging_r14_tags_5,
	sizeof(asn_DEF_multiCarrierPaging_r14_tags_5)
		/sizeof(asn_DEF_multiCarrierPaging_r14_tags_5[0]) - 1, /* 1 */
	asn_DEF_multiCarrierPaging_r14_tags_5,	/* Same as above */
	sizeof(asn_DEF_multiCarrierPaging_r14_tags_5)
		/sizeof(asn_DEF_multiCarrierPaging_r14_tags_5[0]), /* 2 */
	{ &asn_OER_type_multiCarrierPaging_r14_constr_5, &asn_PER_type_multiCarrierPaging_r14_constr_5, NativeEnumerated_constraint },
	0, 0,	/* Defined elsewhere */
	&asn_SPC_multiCarrierPaging_r14_specs_5	/* Additional specs */
};

asn_TYPE_member_t asn_MBR_UE_RadioPagingInfo_NB_r13_1[] = {
	{ ATF_POINTER, 2, offsetof(struct UE_RadioPagingInfo_NB_r13, ue_Category_NB_r13),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ue_Category_NB_r13_2,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"ue-Category-NB-r13"
		},
	{ ATF_POINTER, 1, offsetof(struct UE_RadioPagingInfo_NB_r13, multiCarrierPaging_r14),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_multiCarrierPaging_r14_5,
		0,
		{ 0, 0, 0 },
		0, 0, /* No default value */
		"multiCarrierPaging-r14"
		},
};
static const int asn_MAP_UE_RadioPagingInfo_NB_r13_oms_1[] = { 0, 1 };
static const ber_tlv_tag_t asn_DEF_UE_RadioPagingInfo_NB_r13_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_UE_RadioPagingInfo_NB_r13_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* ue-Category-NB-r13 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 } /* multiCarrierPaging-r14 */
};
asn_SEQUENCE_specifics_t asn_SPC_UE_RadioPagingInfo_NB_r13_specs_1 = {
	sizeof(struct UE_RadioPagingInfo_NB_r13),
	offsetof(struct UE_RadioPagingInfo_NB_r13, _asn_ctx),
	asn_MAP_UE_RadioPagingInfo_NB_r13_tag2el_1,
	2,	/* Count of tags in the map */
	asn_MAP_UE_RadioPagingInfo_NB_r13_oms_1,	/* Optional members */
	1, 1,	/* Root/Additions */
	1,	/* First extension addition */
};
asn_TYPE_descriptor_t asn_DEF_UE_RadioPagingInfo_NB_r13 = {
	"UE-RadioPagingInfo-NB-r13",
	"UE-RadioPagingInfo-NB-r13",
	&asn_OP_SEQUENCE,
	asn_DEF_UE_RadioPagingInfo_NB_r13_tags_1,
	sizeof(asn_DEF_UE_RadioPagingInfo_NB_r13_tags_1)
		/sizeof(asn_DEF_UE_RadioPagingInfo_NB_r13_tags_1[0]), /* 1 */
	asn_DEF_UE_RadioPagingInfo_NB_r13_tags_1,	/* Same as above */
	sizeof(asn_DEF_UE_RadioPagingInfo_NB_r13_tags_1)
		/sizeof(asn_DEF_UE_RadioPagingInfo_NB_r13_tags_1[0]), /* 1 */
	{ 0, 0, SEQUENCE_constraint },
	asn_MBR_UE_RadioPagingInfo_NB_r13_1,
	2,	/* Elements count */
	&asn_SPC_UE_RadioPagingInfo_NB_r13_specs_1	/* Additional specs */
};
