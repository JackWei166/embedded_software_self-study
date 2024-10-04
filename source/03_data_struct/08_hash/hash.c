#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"


hash *hash_create(){
	hash *ht;

	ht = (hash *)malloc(sizeof(hash));
	if(!ht){
		printf("malloc hash failed.\n");
		return NULL;
	}
	
	memset(ht, 0, sizeof(hash));

	return ht;
}

int hash_insert(hash *ht, data_t key){
	linklist p, q;

	if(!ht){
		printf("ht is null.\n");
		return -1;
	}

	p = (linklist)malloc(sizeof(listnode));
	if(!p){
		printf("malloc listnode failed.\n");
		return -1;
	}
	p->key = key;
	p->value = key % N;
	p->next = NULL;

	q = &(ht->data[key%N]);
	while(q->next && q->next->key < p->key){
		q = q->next;
	}

	p->next = q->next;
	q->next = p;

	return 0;
}

linklist  hash_search(hash *ht, data_t key){
	linklist p;

	if(!ht){
		printf("ht is null.\n");
		return NULL;
	}
	
	p = &(ht->data[key%N]);
	while(p->next && p->next->key != key){
		p = p->next;
	}

	if(!p->next){
		return NULL;
	} else {
		return p->next;
	}
}
