/***************************************************************************
 > Filename   : 027.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-18 14:26:04
 > Description: map lhy

 'a' -> "hello a"
 'b' -> "hello b"
 ...

 map[a] = ( 应该可以map出是hello a 字符串就可以 )

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

static const char *hc[] = {
	"hello a",
	"hello b",
	"hello c",
	"hello d",
	"hello e",
	"hello f",
};

static void map_get(const char **map, char elem, char **buf)
{
	*buf = (char *)map[elem - 'a'];
}

int main(int argc, char **argv)
{
	int i;
	int s = sizeof(hc) / sizeof(hc[0]);
	const char **map = (const char **)malloc(s * sizeof(char *));

	if (argc < 2) {
		fprintf(stderr, "argc invalid\n");
		return -1;
	}

	for (i = 0; i < s; i++) {
		map[i] = hc[i];
	}

	char *buf = NULL;
	map_get(map, argv[1][0], &buf);
	printf("buf: %s\n", buf);

	return 0;
}
