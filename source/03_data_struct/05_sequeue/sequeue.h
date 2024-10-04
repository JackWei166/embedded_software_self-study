#ifndef SESqUEUE_H
#define SESqUEUE_H

#define N 128

typedef int data_t;

typedef struct {
	data_t data[N];
	int front;
	int rear;
} sequeue;

sequeue *queue_create();
int enqueue(sequeue *Sq, data_t value);
data_t dequeue(sequeue *Sq);
int queue_empty(sequeue *Sq);
int queue_full(sequeue *Sq);
sequeue *queue_free(sequeue *Sq);

#endif
