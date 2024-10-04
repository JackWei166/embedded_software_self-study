#include <stdio.h>
#include "sqstack.h"

#define N 50

int main(int argc, char *argv[]){
	sqstack *S;

	S = stack_create(N);
	if(!S){
		printf("creating stack failed.");
		return -1;
	}

	stack_push(S, 1);
	stack_push(S, 2);
	stack_push(S, 3);
	stack_push(S, 4);
	stack_push(S, 5);
	
	printf("top:%d\n", stack_top(S));
	
	//stack_clear(S);

	while(!stack_empty(S)){
		printf("pop:%d\n", stack_pop(S));   //xxx  打印什么数据，最好指示出是什么数据
	}

	stack_free(S);

	return 0;
}
