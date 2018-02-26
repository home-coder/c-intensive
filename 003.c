/*************************************************************************
 > Filename   : 003.c
 > Author     : oneface - one_face@sina.com
 > Company    : 江山如画
 > Time       : 2018-02-26 16:58:37
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *p = NULL;
	free(p);

	printf("bye bye\n");

	return 0;
}
