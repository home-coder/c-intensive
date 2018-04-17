/*************************************************************************
 > Filename   : 010.c
 > Author     : oneface - one_face@sina.com
 > Company    : 江山如画
 > Time       : 2018-02-27 15:23:40
 ************************************************************************/

#include <stdio.h>
#include <signal.h>

void handler()
{
	printf("hello\n");
}

int main()
{
	int i;
	signal(SIGALRM, handler);
	alarm(5);
	for (i = 1; i < 1000; i++) {
		printf("sleep %d ...\n", i);
		sleep(1);
		if (i % 5 == 0) {
			alarm(5);
		}
	}
}
