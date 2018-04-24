/***************************************************************************
 > Filename   : 017.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-04-20 14:37:25
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>

int main()
{
	int cmd = 1;

	switch (cmd) {
		case 1:
			goto cmd_1;
			printf("below goto\n");
			break;
		case 2:
			printf("cmd 2\n");
			break;
		default:
			break;
	}
cmd_1:
	printf("on goto \n");
	return 0;
}
