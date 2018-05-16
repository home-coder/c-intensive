/***************************************************************************
 > Filename   : 020.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-09 17:17:31
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#if 1	
static void malloc_buffer(char ***mb, int n)
{
	*mb = (char **)malloc(n * sizeof(char *));
	**mb = (char *)malloc(128 * sizeof(char));
}
#endif

int main()
{
#if 1	
	char **mb = NULL;
	int n = 3;
	int i;

	malloc_buffer(&mb, n);

	mb[0] = "helloworld";
	mb[1] = "wwhave";
	mb[2] = "fffffhave";

	char **pmb = mb;
	for (i = 0; i < n; i++) {
		printf("%s\n", pmb[i]);
	}

	//free

#endif
	/***** more ******/

#if 0
	char *ar[] = {
	"helloworld",
	"fefeilala",
	"huohuohuo",
	};

	char **par = ar;
	int i;

	for (i = 0; i < sizeof(ar) / sizeof(ar[0]); i++) {
		printf("%s\n", *(par + i));
	}
#endif

	return 0;
}
