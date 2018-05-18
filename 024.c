/***************************************************************************
 > Filename   : 024.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-17 14:32:29
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/

// 2014 - 2018, 2006-2007-2008-2009-2010, 2010-2014, 2016-2018,1993
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void revert_char_bit(char src, char **dst)
{
	int i = 0;

	*dst = (char *)malloc(9 * sizeof(char));
	for (i = 0; i < 8; i++) {
		(*dst)[7-i] = '0' + ((src & (0x1 << i)) >> i); // 移位运算符等 优先级 括号，需要好好掌握
	}
	(*dst)[8] = '\0';

	printf("dst = %s\n", *dst);
}

int main(int argc, char **argv)
{
	if (argc < 2) {
		fprintf(stderr, "argc error\n");
		return -1;
	}

	/*  计算机代码中没有二进制这种表示方法
	    只能是 8，10，16进制
		8：   前置 0
		10：  不需前置
		16：  前置 0x 或者 0X 
	*/
	printf("do = %d\n", 012);
	printf("do = %d\n", 012);
	printf("do = %d\n", 0x12);

	char src = argv[1][0];
	printf("src = %c\n", src);

	char *dst = NULL;
	revert_char_bit(src, &dst);

	printf("dst = %s\n", dst);

	return 0;
}
