/***************************************************************************
 > Filename   : 025.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-17 16:44:46
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

static void change_func(char **p)
{
	*p = "hello world";
}

int main()
{
	char *p = NULL;

	change_func(&p);

	printf("p = %s\n", p);

	
	int i;
	char *p2 = (char *)malloc(8 * sizeof(char));
	for (i = 0; i < 8; i++) {
		p2[i] = '0' + i;
	}
	printf("p2= %s\n", p2);

	return 0;
}
