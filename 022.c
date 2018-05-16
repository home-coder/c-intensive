/***************************************************************************
 > Filename   : 022.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-16 15:00:00
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int parent;
}hftree;

static void huffman_code(char ***hfc, hftree *hft, int s)
{
	int i;
	for (i = 1; i <= s; i++) {
		printf("before:%d ", hft[i].parent);
	}
	printf("\n");

	char *code = (char *)malloc(s * sizeof(char));
	if (!code) {
		printf("code malloc failed\n");
		return ;
	}
	code[s - 1] = '\0';

	*hfc = (char **)malloc(s * sizeof(**hfc));
	if (!hfc) {
		printf("*hfc malloc failed\n");
		return ;
	}

	for (i = 1; i <= s; i++) {
		printf("after:%d ", hft[i].parent);
	}
	printf("\n");
}

int main()
{
	int i;
	int s = 9;
	int m = 2 * s - 1;
	char **hfc = NULL;

	hftree *hft = (hftree *)malloc((m + 1) * sizeof(*hft));
	for (i = 1; i < m; i++) {
		hft[i].parent = -1;	
	}

	huffman_code(&hfc, hft, s);

	return 0;
}
