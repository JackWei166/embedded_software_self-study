#ifndef _ARR_
#define _ARR_

typedef struct arr{
	int data[100];
	int tail;

	void (*addtail)(struct arr *arr, int data);
	void (*show)(struct arr *arr);
} ARR;

void init(struct arr *arr);

#endif
