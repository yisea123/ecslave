#ifndef __EC_COE_H__
#define __EC_COE_H__

#include "ec_mbox.h"


enum {
	OD_LIST_REQUEST   = 0x01,	
	OD_LIST_RESPONSE  = 0x02,
	OBJ_DESC_REQUEST  = 0x03,
	OBJ_DESC_RESPONSE = 0x04,
	ENTRY_DESC_REQUEST = 0X05,
	ENTRY_DESC_RESPONSE = 0X06,
	SDO_INFO_ERROR_REQUEST  = 0X07
}sdo_info_hdr_opcode;

#define MBOX_COE_TYPE 0x03
#define NR_SDOS 8

void coe_parser(int reg, uint8_t * data, int datalen);

// table 42
typedef struct {
	uint16_t list_type;
}coe_sdo_service_data;

static inline coe_sdo_service_data *__coe_sdo_service_data(uint8_t *data)
{
	return (coe_sdo_service_data *)
		&data[sizeof(mbox_header) + 
		sizeof(coe_header) + 
		sizeof(coe_sdo_info_header)];
}

typedef struct __coe_sdo__ {

	mbox_header mbxhdr;
	coe_header coehdr;
	uint8_t res:4, complete_access:1, cmd:3;
	uint16_t index;
	uint8_t subindex;
	uint8_t data[4];
}coe_sdo;

#endif
