#include <stdio.h>
#include "linklist.h"


void test_insert();
void test_delete();
void test_reverse();
void test_adjmax();

int main(int argc, char *argv[]){
	//test_insert();
	//test_delete();
	//test_reverse();
	test_adjmax();

	return 0;
}

void test_insert(){
	linklist H;
	int value;

	if(!(H = list_create())){
		printf("Creating list failed.");
		return;
	}

	printf("input:");
	while(1){
		scanf(" %d", &value);
		if(value == -1){
			break;
		}
		list_tail_insert(H, value);
		printf("input:");
	}

	list_show(H);

	list_insert(H, 66, 0);

	list_show(H);

	list_free(H);
}

void test_delete(){
	linklist H;
	int value;

	if(!(H = list_create())){
		printf("Creating list failed.");
		return;
	}

	printf("input:");
	while(1){
		scanf(" %d", &value);
		if(value == -1){
			break;
		}
		list_tail_insert(H, value);
		printf("input:");
	}

	list_show(H);

	list_delete(H, 0);

	list_show(H);

	list_free(H);
}

void test_reverse(){
	linklist H;
	int value;

	if(!(H = list_create())){
		printf("Creating list failed.");
		return;
	}

	printf("input:");
	while(1){
		scanf(" %d", &value);
		if(value == -1){
			break;
		}
		list_tail_insert(H, value);
		printf("input:");
	}

	list_show(H);

	list_reverse(H);

	list_show(H);

	list_free(H);
}

void test_adjmax(){
	linklist H, padjmax;
	int value, max;

	if(!(H = list_create())){
		printf("Creating list failed.");
		return;
	}

	printf("input:");
	while(1){
		scanf(" %d", &value);
		if(value == -1){
			break;
		}
		list_tail_insert(H, value);
		printf("input:");
	}

	list_show(H);

	padjmax = list_adjmax(H, &max);
	if(padjmax){ 
		printf("adjmax:%d %d\nmax:%d\n", padjmax->data, padjmax->next->data, max);
	}

	list_free(H);
}
