/***************************************************************************
 > Filename   : 032.c
 > Author     : oneface - one_face@sina.com
 > Company    : 一尊还酹江月
 > Time       : 2018-05-30 09:12:33
 > Description: 

 - This program is free software; you can redistribute it and/or modify it
 - under the terms of the GNU General Public License as published by the
 - Free Software Foundation;  either version 2 of the  License, or (at your
 - option) any later version.
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define AS	256  //ASCCI 可打印0-127  扩展128-256

typedef struct {
	int weight;
}myhfm;

static void sort_myhfm(myhfm *mhfm)
{
	int i, j;
	myhfm tmp;

	for (i = 0; i < AS; i++) {
		for (j = 0; j < AS - i; j++) {
			if (mhfm[j].weight < mhfm[j + 1].weight) {
				tmp = mhfm[j];
				mhfm[j] = mhfm[j + 1];
				mhfm[j + 1] = tmp;	
			}
		}
	}
}

static void creat_myhfm(myhfm **pmhfm, char *data)
{
	int i;
	*pmhfm = (myhfm *)malloc(AS * sizeof(**pmhfm));

	i = 0;
	while (i++ < AS) {
		(*pmhfm)[i].weight = 0;	
	}
	while (*data) {
		(*pmhfm)[*data].weight++;
		data++;
	}

	sort_myhfm(*pmhfm);
}

static void print(myhfm *mhfm)
{
	int i;
	for (i = 0; i < AS; i++) {
		if (mhfm[i].weight == 0) {
			break;
		}
		printf("%c:%d\n", i, mhfm[i].weight);
	}
}

int main()
{
	char *data = "hbhekdlskekgdktsklaadbk";
	myhfm *mhfm = NULL;

	creat_myhfm(&mhfm, data);
	print(mhfm);

}
