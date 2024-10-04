#ifndef _ARR_
#define _ARR_

typedef struct arr{
	int data[100];
	int tail;
} ARR;

void init(ARR *arr);
void addtail(ARR *arr, int data);
void show(ARR *arr);

#endif
