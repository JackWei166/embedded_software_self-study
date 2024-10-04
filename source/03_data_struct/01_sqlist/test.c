#include <stdio.h>
#include "sqlist.h"

void test_purge();
void test_insert();
void test_delete();
void test_merge();

void test_clear();
void test_empty();
void test_length();

int main(int argc, char *argv[]){
	//test_insert();
	//test_delete();
	//test_merge();
	//test_purge();
	
	//test_clear();
	//test_empty();
	test_length();

	return 0;
}

void test_insert(){
	sqlink L;

	L = list_create();
	if(L == NULL)
		return;

	list_insert(L, 0, 0);
	list_insert(L, 1, 1);
	list_insert(L, 2, 2);
	list_insert(L, 3, 3);
	list_insert(L, 4, 4);
	list_insert(L, 5, 5);

	list_show(L);

	list_free(L);
}

void test_delete(){
	sqlink L;

	L = list_create();
	if(L == NULL)
		return;

	list_insert(L, 0, 0);
	list_insert(L, 1, 1);
	list_insert(L, 2, 2);
	list_insert(L, 3, 3);
	list_insert(L, 4, 4);
	list_insert(L, 5, 5);
	
	list_show(L);

	list_delete(L, 2);

	list_show(L);

	list_free(L);
}

void test_merge(){
	sqlink L1, L2;

	L1 = list_create();
	if(!L1)
		return;

	L2 = list_create();
	if(!L2)
		return;

	list_insert(L1, 0, 0);
	list_insert(L1, 1, 1);
	list_insert(L1, 2, 2);
	list_insert(L1, 3, 3);
	list_insert(L1, 4, 4);
	list_insert(L1, 5, 5);

	list_insert(L2, 6, 0);
	list_insert(L2, 1, 1);
	list_insert(L2, 2, 2);
	list_insert(L2, 3, 3);
	list_insert(L2, 5, 4);
	list_insert(L2, 7, 5);


	list_show(L1);
	list_show(L2);

	list_merge(L1, L2);

	list_show(L1);
	list_show(L2);

	list_free(L1);
	list_free(L2);
}

void test_purge(){
	sqlink L;

	L = list_create();
	if(L == NULL)
		return;

	list_insert(L, 1, 0);
	list_insert(L, 1, 1);
	list_insert(L, 2, 2);
	list_insert(L, 3, 3);
	list_insert(L, 3, 4);
	list_insert(L, 6, 5);

	list_show(L);

	list_purge(L);

	list_show(L);

	list_free(L);
}


void test_clear(){
	sqlink L;

	L = list_create();
	if(L == NULL)
		return;

	list_insert(L, 0, 0);
	list_insert(L, 1, 1);
	list_insert(L, 2, 2);
	list_insert(L, 3, 3);
	list_insert(L, 4, 4);
	list_insert(L, 5, 5);
	
	list_show(L);

	list_clear(L);

	list_show(L);

	list_free(L);
}

void test_empty(){
	sqlink L;

	L = list_create();
	if(L == NULL)
		return;
	
	printf("%d\n", list_empty(L));

	list_insert(L, 0, 0);
	list_insert(L, 1, 1);
	list_insert(L, 2, 2);
	list_insert(L, 3, 3);
	list_insert(L, 4, 4);
	list_insert(L, 5, 5);
	
	list_show(L);

	printf("%d\n", list_empty(L));

	list_free(L);
}

void test_length(){
	sqlink L;

	L = list_create();
	if(L == NULL)
		return;
	
	printf("%d\n", list_length(L));

	list_insert(L, 0, 0);
	list_insert(L, 1, 1);
	list_insert(L, 2, 2);
	list_insert(L, 3, 3);
	list_insert(L, 4, 4);
	list_insert(L, 5, 5);
	
	list_show(L);

	printf("%d\n", list_length(L));

	list_free(L);
}
