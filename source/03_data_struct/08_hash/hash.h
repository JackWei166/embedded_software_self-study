#ifndef HASH_H
#define HASH_H

#define N 128

typedef int data_t;

typedef struct node {
	data_t key;
	int value;
	struct node *next;
} listnode, *linklist;

typedef struct {
	listnode data[N];
} hash;

hash *hash_create();
int hash_insert(hash *ht, data_t key);
linklist hash_search(hash *ht, data_t key);   //xxx 对，插入查找，都得需要值，不能光一个哈希数据结构就行了的！

#endif
