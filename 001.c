/*************************************************************************
 > Filename   : 001.c
 > Author     : oneface - one_face@sina.com
 > Company    : 江山如画
 > Time       : 2018-02-26 09:26:11
 ************************************************************************/

#include <stdio.h>

int main()
{
	int a = 10;
	printf("a = %u\n", a);
	printf("a = %d\n", a);

	unsigned long b = 11;
	long c = 12;
	printf("b = %lu\n", b);
	printf("c = %lu\n", c);

	char *p = (char *)0x12345678;
	printf("p = %p\n", p);

	int q = 0x87654321;
	printf("q = 0x%x\n", q);

	unsigned char m = 0x4;
	printf("m = 0x%x\n", m);

	return 0;
}
