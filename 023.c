/***************************************************************************
 > Filename   : 023.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-16 15:42:26
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)  
{  
	char *buf;  

	buf = malloc(1<<31);  

	fgets(buf, 1024, stdin);  
	printf("%s\n", buf);  

	return 0;  
}

