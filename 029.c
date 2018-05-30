/***************************************************************************
 > Filename   : 029.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-21 11:28:54
 > Description: 
 file operations
 fopen fread fwrite fseek ftell ...

 搞清楚下面的问题，并且重复练习
 {
	一行一行的读取文件
	二进制和文本文件的不同
 }

 搞清楚字符 字符串 数字 Assic码等概念

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define TESTFILE	"../project-setenv-resolution/boot.ini"
//#define TESTFILE	"testdata/repeat_0000.wav"
#define TESTFILE	"testdata/repeat_0001.wav"

int main()
{
	FILE *fp = NULL;
	char linebuf[512];

	if ((fp = fopen(TESTFILE, "rb")) == NULL) {
		fprintf(stderr, "open failed\n");
		exit(-1);
	}

#ifdef TEXT
	//read and write to /dev/tty1
	while (fgets(linebuf, 512, fp)) {
		//fwrite(linebuf, 512, 1, stdout); //分析这样写，a.out结果为何乱码
		fwrite(linebuf, strlen(linebuf), 1, stdout);
	}
#endif

#ifdef BINARY
	char bits, bit;
	while (fread(&bits, 1, 1, fp)) {
		int j = 8;
		while (j--) {
			bit = bits >> j;
			printf("%d", bits);
		}
		printf(" ");
	}
#endif

	return 0;
}
