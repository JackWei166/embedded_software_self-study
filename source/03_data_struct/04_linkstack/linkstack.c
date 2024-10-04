#include <stdio.h>
#include <stdlib.h>
#include "linkstack.h"


linkstack stack_create(){
	linkstack S;

	S = (linkstack)malloc(sizeof(listnode));
	if(!S){
		printf("malloc linkstack failed.\n");
		return NULL;
	}
	
	S->data = 0;
	S->next = NULL;

	return S;
}

int stack_push(linkstack S, data_t value){
	linkstack p;

	if(!S){
		printf("stack is null.\n");   //xxx 有必要吗？觉得有时间可以搜搜看看；觉得用处可能是避免运行下去报更大的错吧，但觉得null出现概率应该也是很低的
		return -1;
	}
	
	p = (linkstack)malloc(sizeof(listnode));
	if(!p){
		printf("malloc linkstack failed.\n");
		return -1;
	}

	p->data = value;
	p->next = NULL;

	p->next = S->next;
	S->next = p;

	return 0;
}

data_t stack_pop(linkstack S){
	linkstack p;
	data_t t;

	if(!S){
		printf("stack is null.\n");
		return -1;
	}
	
	p = S->next;
	
	S->next = p->next;
	
	t = p->data;

	free(p);
	p = NULL;

	return t;
}

int stack_empty(linkstack S){
	if(!S){
		printf("stack is null.\n");
		return -1;
	}

	return S->next == NULL ? 1 : 0;
}

data_t stack_top(linkstack S){
	if(!S){
		printf("stack is null.\n");
		return -1;
	}

	return S->next->data;
}

linkstack stack_free(linkstack S){
	linkstack p;

	if(!S){
		printf("stack is null.\n");
		return NULL;
	}

	while(!S){
		p = S;

		S = S->next;

		printf("free:%d\n", p->data);
		free(p);
		p = NULL;
	}

	return NULL;
}
