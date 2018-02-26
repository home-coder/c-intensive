/*************************************************************************
 > Filename   : 004.c
 > Author     : oneface - one_face@sina.com
 > Company    : 江山如画
 > Time       : 2018-02-26 18:42:48
 ************************************************************************/

#include <stdio.h>

#define TEST_3 1

int main()
{
#if TEST_0
	//没有const, 虽然操作了只读常量区但是编译过程通过，所以为了让其编译也不通过，最好的编码方式是当时就加上一个const
	char *str = "helloworld";
	str[3] = 'm';
#endif

#if TEST_1
	//编译就会报错，const 在C语言中并不是强制的保护作用，仅仅起到给编译器看的作用
	const char *str = "helloworld";
	str[3] = 'm';
#endif

#if TEST_2
	const char * const str = "helloworld";
	str = "mall";
#endif

#if TEST_3
	const char * str = "helloworld";
	str = "mall";
#endif
	return 0;
}
