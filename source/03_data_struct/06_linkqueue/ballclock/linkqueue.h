#ifndef LINKQUEUE_H
#define LINKQUEUE_H

typedef int data_t;

typedef struct node {
	data_t data;
	struct node *next;
} listnode, *linklist;   //xxx 说我struct end 没分号，原来是内部end

typedef struct {
	linklist front;
	linklist rear;
} linkqueue;

linkqueue *queue_create();
int enqueue(linkqueue *Lq, data_t value);
data_t dequeue(linkqueue *Lq);
int queue_empty(linkqueue *Lq);
int queue_clear(linkqueue *Lq);
linkqueue *queue_free(linkqueue *Lq);

#endif
