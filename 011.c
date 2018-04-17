/*************************************************************************
 > Filename   : 011.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-02-28 13:18:00
 ************************************************************************/

#include <stdio.h>
#include <stdint.h>

int main()
{
	uint32_t *per_sample, *data_tmp;
	uint16_t b;
	printf("uint32 %lu\n", sizeof(uint32_t));

	*data_tmp = (uint32_t) 0x12345678;
	printf("per_sample 0x%x\n", *data_tmp);

	printf("per_sample 0x%x\n", (uint32_t) * data_tmp);

	return 0;
}
