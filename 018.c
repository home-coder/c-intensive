/***************************************************************************
 > Filename   : 018.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-04-24 14:16:02
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>

int main()
{
	char *s = "\"";
	// FIXME ERROR char *s = """;

	printf("%s\n", s);


	char text1[] =
		        "{\n\"name\": \"Jack (\\\"Bee\\\") Nimble\", \n\"format\": {\"type\":       \"rect\", \n\"width\":      1920, \n\"height\":     1080, \n\"interlace\":  false,\"frame rate\": 24\n}\n}";
	printf("%s\n", text1);

	return 0;
}
