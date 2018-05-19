/***************************************************************************
 > Filename   : 028.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-19
 > Description: to bits  lhy

 'a' -> "00110"
 'b' -> "110001"
 ...

 input a b , output  54 -> '6' ->(00110110) +  '001'
 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX 16
static char *hc[] = {
	"00110",
	"110001",
	"1001",
	"11100011",
	"01010101",
	"0011111",
};

typedef struct {
	int front, rear;
	char elem[MAX];
	unsigned int length;
}aqueue; //array;

static void creat_queue(aqueue **aque)
{
	*aque = (aqueue *)malloc(sizeof(**aque));
	(*aque)->front = (*aque)->rear = 0;
	(*aque)->length = 0;
}

static void en_queue(aqueue *aque, char elem)
{
	if (aque->rear != 0 && aque->rear % MAX == aque->front) {
		printf("queue is full\n");
		return ;
	}

	aque->elem[aque->rear] = elem;
	aque->rear++;
	aque->length++;
}

static int de_queue(aqueue *aque, char *elem)
{
	if (aque->front != 0 && aque->front % MAX == aque->rear) {
		printf("queue is null\n");
		return -1;
	}

	*elem = aque->elem[aque->front];
	aque->front++;
	aque->length--;

	return 0;
}

int main(int argc, char **argv)
{
	int i, j = 8;
	char bit, bits = 0;
	int s = sizeof(hc) / sizeof(hc[0]);

	if (argc < 2) {
		fprintf(stderr, "argc invalid\n");
		return -1;
	}

	//一个好的通用队列如何设计
	aqueue *aque = NULL;
	creat_queue(&aque);

	for (i = 1; i < argc; i++) {
		char *pc = hc[argv[i][0] - 'a'];
		printf("%s\n", pc);
		while (*pc) {
			en_queue(aque, *pc);
			pc++;
		}
		printf("l=%d\n", aque->length);
		while (aque->length > 8) {
			while (j--) {
				de_queue(aque, &bit);
				//如何把字符'0' '1' '0' ...压入字符变量bit (8bit 类型)当中
				printf("bit = %c\n", bit);
				bits = bits | ((bit - '0') << j);
			}
			printf("bits = %c\n", bits);
			//TODO fwrite file
		}
	}

	return 0;
}
