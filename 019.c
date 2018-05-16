/***************************************************************************
 > Filename   : 019.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-04-24 15:31:26
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>

int main()
{
	char *ptr = "h1234 world";
	unsigned int uc;
	sscanf(ptr + 1, "%4x", &uc);

	printf("%d\n", uc);

	return 0;
}
