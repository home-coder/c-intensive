/***************************************************************************
 > Filename   : arr.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-14 09:17:54
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#if 0
int *return_arr()
{
	int arr[] = {1, 2, 3};
	return arr;
}
#endif

int *return_arr()
{
	int *arr = (int *)malloc(3 * sizeof(int));
	int iarr[] = {1, 2, 3};
	int i;

	for (i = 0; i < sizeof(iarr) / sizeof(iarr[0]); i++) {
		*(arr  + i) = iarr[i];
	}

	return arr;
}

int main()
{
	int *ap = return_arr();

	int i;
	for (i = 0; i < 3; i++) {
		printf("%d\n", *(ap + i));
	}

	free(ap);

	return 0;
}
