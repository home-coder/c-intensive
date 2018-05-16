/*************************************************************************
 > Filename   : 003.c
 > Author     : oneface - one_face@sina.com
 > Company    : 江山如画
 > Time       : 2018-02-26 16:58:37
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#if 0
int main()
{
	char *p = NULL;
	free(p);

	printf("bye bye\n");

	return 0;
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *s = "hello";
	char *m = (char *)malloc(10);
	memcpy(m, s, strlen(s));
	printf("%s\n", m);
	char *p = m;
	char *q = m;

	free(p);
	p = NULL;

	printf("q = %s\n", q);
	printf("%s\n", m);

	char *t = NULL;
	free(t);
//这才有意义
	printf("a ha\n");
	free(m);
	m = NULL;

	return 0;
}
#endif
/*************************************************************************
 > Filename   : free2.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-04-16 16:27:19
 ************************************************************************/

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data {
	char *name;
	int age;
} student;

student *stu_create(char *name, int age)
{
	student *stu = (student *) malloc(sizeof(student));
	stu->name = name;
	stu->age = age;
	return stu;
}

void stu_release(student * stu)
{
	free(stu);
}

int main()
{
	char *name = "abc";
	printf("%s\n", name);
	student *stu = stu_create(name, 10);
	printf("%s %d\n", stu->name, stu->age);
	stu_release(stu);
	stu = NULL;
	return 0;
}
#endif

#if 1

void malloc_ar(int **ar, int s)
{
	int i;
	*ar = (int *)malloc(s * sizeof(int));
	for (i = 0; i < s; i++) {
		(*ar)[i] = i;
	}
}

int main()
{
	int *ar = NULL;
	int i;
	malloc_ar(&ar, 5);

	for (i = 0; i < 5; i++) {
		printf("%d ", ar[i]);
	}
	printf("\n");
	free(ar);
	return 0;
}
#endif
