#include <stdio.h>
#include "hash.h"

int main(int argc, char *argv[]){
	hash *ht;
	int data[] = {13, 21, 36, 48, 51, 62};
	int i, key;
	linklist r;

	ht = hash_create();
	if(!ht){
		printf("create hash failed.\n");
		return -1;
	}

	for(i = 0; i < sizeof(data)/sizeof(int); i++){   //xxx sizeof求数组个数，得字节数除以字节数
		hash_insert(ht, data[i]);
	}

	printf("input:");
	scanf("%d", &key);

	r = hash_search(ht, key);
	if(!r){
		printf("not found\n");
	} else {
		printf("found:%d %d\n", key, r->key);
	}

	return 0;
}
