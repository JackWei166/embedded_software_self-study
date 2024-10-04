#include <stdio.h>
#include "linkqueue.h"

int main(int argc, char *argv[]){
	linkqueue *Lq;
	
	Lq = queue_create();
	if(!Lq){
		printf("create queue failed.\n");
		return -1;
	}

	enqueue(Lq, 1);
	enqueue(Lq, 2);
	enqueue(Lq, 3);
	enqueue(Lq, 4);
	enqueue(Lq, 5);

	while(!queue_empty(Lq)){
		printf("de:%d\n", dequeue(Lq));
	}

	queue_free(Lq);

	return 0;
}
