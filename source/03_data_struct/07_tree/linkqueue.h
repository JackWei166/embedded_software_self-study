#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "tree.h"

typedef bitree *data_type;

typedef struct node_t {
	data_type data;
	struct node_t *next;
} listnode, *linklist;   //xxx 说我struct end 没分号，原来是内部end

typedef struct {
	linklist front;
	linklist rear;
} linkqueue;

linkqueue *queue_create();
int enqueue(linkqueue *Lq, data_type value);
data_type dequeue(linkqueue *Lq);
int queue_empty(linkqueue *Lq);
int queue_clear(linkqueue *Lq);
linkqueue *queue_free(linkqueue *Lq);

#endif
