/*************************************************************************
 > Filename   : 009.c
 > Author     : oneface - one_face@sina.com
 > Company    : 江山如画
 > Time       : 2018-02-27 15:11:25
 ************************************************************************/

#include <stdio.h>

int main()
{
	char repeat_idx[256];

	sprintf(repeat_idx, "helloworld");
	sprintf(repeat_idx, "hello");

	printf("repeat_idx is %s\n", repeat_idx);

	return 0;
}
