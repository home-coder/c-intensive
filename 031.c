/***************************************************************************
 > Filename   : 031.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-23 17:29:16
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>

int main()
{
	char *p = "195678876523456789";

	char *p_p = p;

	while (*p_p) {
		printf("%c\n", *p++);
	}
	printf("\n");

	return 0;
}
