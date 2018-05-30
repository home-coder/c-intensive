/***************************************************************************
 > Filename   : 033.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-30 10:03:24
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>

static void sort(int *w, int s)
{
	int tmp, i, j;

	for (i = 0; i < s; i++) {
		for (j = 0; j < s - i; j++) {
			if (w[j] < w[j + 1]) {
				tmp = w[j];
				w[j] = w[j + 1];
				w[j + 1] = tmp;
			}
		}
	}
}

static void print(int *w, int s)
{
	int i;

	for (i = 0; i < s; i++) {
		printf("%d ", *(w + i));
	}
	printf("\n");
}

int main()
{
	int w[] = {8, 3, 2, 2, 1, 7, 5, 8, 9, 0};

	sort(w, sizeof(w) / sizeof(w[0]));
	print(w, sizeof(w) / sizeof(w[0]));

	return 0;
}
