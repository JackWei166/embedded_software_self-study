#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sequeue.h"

sequeue *queue_create(){
	sequeue *Sq;

	Sq =(sequeue *)malloc(sizeof(sequeue));
	if(!Sq){
		printf("malloc sequeue failed.\n");
		return NULL;
	}

	memset(Sq->data, 0, sizeof(sequeue));
	Sq->front = 0;
	Sq->rear = 0;

	return Sq;
}

int enqueue(sequeue *Sq, data_t value){
	if(!Sq){
		printf("sequeue is null.\n");
		return -1;
	}

	if((Sq->rear + 1) % N == Sq->front){
		printf("sequeue is full.\n");
		return -1;
	}

	Sq->data[Sq->rear] = value;

	Sq->rear = (Sq->rear + 1) % N;

	return 0;
}

data_t dequeue(sequeue *Sq){
	data_t ret;

	if(!Sq){
		printf("sequeue is null.\n");
		return -1;
	}

	ret = Sq->data[Sq->front];

	Sq->front = (Sq->front + 1) % N;

	return ret;
}

int queue_empty(sequeue *Sq){
	if(!Sq){
		printf("sequeue is null.\n");
		return -1;
	}

	return Sq->front == Sq->rear ? 1 : 0;   //xxx 相等为空，就是这么设计的，加入数据，rear向上走，处理数据front向上走，符合先进先出
}

int queue_full(sequeue *Sq){
	if(!Sq){
		printf("sequeue is null.\n");
		return -1;
	}

	return (Sq->rear + 1) % N == Sq->front ? 1 : 0;
}

int queue_clear(sequeue *Sq){
	if(!Sq){
		printf("sequeue is null.\n");
		return -1;
	}

	Sq->front = Sq->rear = 0;

	return 0;
}

sequeue *queue_free(sequeue *Sq){
	if(!Sq){
		printf("sequeue is null.\n");
		return NULL;
	}

	free(Sq);
	Sq = NULL;

	return NULL;
}
