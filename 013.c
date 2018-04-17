/*************************************************************************
 > Filename   : 013.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-03-02 09:51:24
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

/*  len += snprintf(buf+len, PAGE_SIZE-len, "hwen=%d\n",.... */

#define PAGE_SIZE 4096

static int my_read(char *buf)
{
	int len = 0, i;
	char *data_arry[] = {
		"hello",
		"today",
		"dog",
		"happy sunday",
		"india asan movie"
	};

	for (i = 0; i < sizeof(data_arry) / sizeof(data_arry[0]); i++) {
		len += snprintf(buf + len, PAGE_SIZE - len, "%s-", data_arry[i]);
	}

	return len;
}

int main()
{
	int ret = -1;
	char *buf = NULL;
	buf = (char *)malloc(sizeof(char) * 256);
	if (!buf) {
		printf("buf malloc failed\n");
		return -1;
	}
	ret = my_read(buf);
	printf("ret = %u\nbuf =%s\n", ret, buf);
	free(buf);
	buf = NULL;

	return 0;
}
