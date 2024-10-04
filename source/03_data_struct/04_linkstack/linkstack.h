#ifndef LINKSTACK_H
#define LINKSTACK_H

typedef int data_t;

typedef struct node {
	data_t data;
	struct node *next;
} listnode, *linkstack;

linkstack stack_create();
int stack_push(linkstack S, int value);
data_t stack_pop(linkstack S);
int stack_empty(linkstack S);
data_t stack_top(linkstack S);
linkstack stack_free(linkstack S);

#endif
