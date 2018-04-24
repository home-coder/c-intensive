/***************************************************************************
 > Filename   : 016.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-04-19 14:15:22
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>

typedef enum {false, true}bool;

int main()
{
	unsigned long arg;

	arg = (unsigned long)true;

	printf("%lu\n", arg);

	bool m = (bool)arg;
	if (m) {
		printf("-----------------\n");
	}
	return 0;	
}
