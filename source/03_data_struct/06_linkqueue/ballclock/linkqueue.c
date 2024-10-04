#include <stdio.h>
#include <stdlib.h>
#include "linkqueue.h"


linkqueue * queue_create(){
	linkqueue *Lq;

	Lq = (linkqueue *)malloc(sizeof(linkqueue));
	if(!Lq){
		printf("malloc linkqueue failed.\n");
		return NULL;
	}

	Lq->front = Lq->rear = (linklist)malloc(sizeof(listnode));
	if(!Lq->front){
		printf("malloc listnode failed.\n");
		return NULL;
	}

	Lq->front->data = 0;
	Lq->front->next = NULL;

	return Lq;
}

int enqueue(linkqueue *Lq, data_t value){
	linklist p;

	if(!Lq){
		printf("linkqueue is null.\n");
		return -1;
	}

	p = (linklist)malloc(sizeof(listnode));
	if(!p){
		printf("malloc listnode failed.\n");
		return -1;
	}
	p->data = value;
	p->next = NULL;

	Lq->rear->next = p;

	Lq->rear = p;

	return 0;
}

data_t dequeue(linkqueue *Lq){
	linklist p;
	//data_t t;

	if(!Lq){
		printf("linkqueue is null.\n");
		return -1;
	}

	p = Lq->front;
	//t = p->data;   //xxx 链表中的front不指向实际数据，所以不用保留；移动后指向的数返回 移动后的也就不指向了

	Lq->front = p->next;

	free(p);
	p = NULL;

	return Lq->front->data;
}

int queue_empty(linkqueue *Lq){
	if(!Lq){
		printf("linkqueue is null.\n");
		return -1;
	}

	return Lq->front == Lq->rear ? 1 : 0;
}

int queue_clear(linkqueue *Lq){
	linklist p;

	if(!Lq){
		printf("linkqueue is null.\n");
		return -1;
	}

	while(Lq->front->next){
		p = Lq->front;
		
		Lq->front = p->next;
		
		printf("clear free:%d\n", p->data);
		free(p);
		p = NULL;
	}

	return 0;
}

linkqueue *queue_free(linkqueue *Lq){
	linklist p;

	if(!Lq){
		printf("linkqueue is null.\n");
		return NULL;
	}

	while(Lq->front){
		p = Lq->front;

		Lq->front = p->next;

		printf("free:%d\n", p->data);
		free(p);
		p = NULL;
	}

	free(Lq);
	Lq = NULL;

	return NULL;
}
