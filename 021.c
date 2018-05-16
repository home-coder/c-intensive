#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define CBWCDBLENGTH    16

#define CBWSIGNATURE    (0x43425355)
#define CSWSIGNATURE    (0x53425355)
/* Command Block Wrapper */
struct umass_bbb_cbw_t
{
	__u32       dCBWSignature;
	__u32       dCBWTag;
	__u32       dCBWDataTransferLength;
	__u8        bCBWFlags;
	__u8        bCBWLUN;
	__u8        bCDBLength;
	__u8        CBWCDB[CBWCDBLENGTH];
}__attribute__ ((packed));

/* Command Status Wrapper */
struct umass_bbb_csw_t
{
	__u32       dCSWSignature;
	__u32       dCSWTag;
	__u32       dCSWDataResidue;
	__u8        bCSWStatus;
}__attribute__ ((packed));

typedef struct {
	char magic_name[8];
	int count;
	int reserved[3];
}USER_DATA_HEAR;


typedef unsigned char uchar;
typedef unsigned int  uint;

typedef struct
{

	uchar *base_recv_buffer;		//存放接收到的数据的首地址，必须足够大

	uint   act_recv_buffer;//

	uint   recv_size;

	uint   to_be_recved_size;

	uchar *base_send_buffer;		//存放将要到的数据的首地址，必须足够大

	uint   act_send_buffer;//

	uint   send_size;		//需要发送数据的长度

	uint   flash_start;			//起始位置，可能是内存，也可能是flash扇区

	uint   flash_sectors;

}
pburn_trans_set_t;


int main()
{
	printf("size= 0x%lx\n", sizeof(int));
	printf("size= 0x%lx\n", sizeof(struct umass_bbb_cbw_t));
	printf("size= 0x%lx\n", sizeof(USER_DATA_HEAR));
	USER_DATA_HEAR udh;
	printf("magic:%p, count:%p, reserved:%p\n", &udh.magic_name, &udh.count, &udh.reserved);

	pburn_trans_set_t pts;
	pts.base_recv_buffer = "hello world";
	printf("pts.brb: %s\n", pts.base_recv_buffer);
	pts.act_recv_buffer = (uint)pts.base_recv_buffer;
	printf("pts.brb: %s\n", pts.act_recv_buffer);

	return 0;
}
