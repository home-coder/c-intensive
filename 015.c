/***************************************************************************
 > Filename   : 015.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-04-19 10:23:27
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>

char *p = NULL;

void func2(char *m)
{
	p = m;
#if 0 //加上这一句./a.out执行结果会有神奇的事情，函数printf调用栈
	//printf("p = %s\n", p);
#endif
}

void func1()
{
	char m[20] = {"hello world"};
	
	//char *m = "weiweiwei";
	//p = m;
	//printf("p = %s\n", p);

	func2(m);
}

int main()
{
	func1();
	printf("p = %s\n", p);

	return 0;
}
