#ifndef SQLIST_H
#define SQLIST_H

#define N 50

typedef int data_t;

typedef struct {
	data_t data[N];
	int last;
} sqlist, *sqlink;

sqlink list_create();
int list_clear(sqlink L);
int list_free(sqlink L);
int list_empty(sqlink L);
int list_length(sqlink);
int list_locate(sqlink L, data_t value);
int list_insert(sqlink L, data_t value, int pos);
int list_delete(sqlink L, int pos);
int list_merge(sqlink L1, sqlink L2);
int list_purge(sqlink L);
int list_show(sqlink L);

#endif