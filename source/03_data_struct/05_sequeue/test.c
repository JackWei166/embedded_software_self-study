#include <stdio.h>
#include "sequeue.h"

int main(int argc, char *argv[]){
	sequeue *Sq;
	
	Sq = queue_create();
	if(!Sq){
		printf("create queue failed.\n");
		return -1;
	}

	enqueue(Sq, 1);
	enqueue(Sq, 2);
	enqueue(Sq, 3);
	enqueue(Sq, 4);
	enqueue(Sq, 5);

	while(!queue_empty(Sq)){
		printf("de:%d\n", dequeue(Sq));
	}

	queue_free(Sq);

	return 0;
}
