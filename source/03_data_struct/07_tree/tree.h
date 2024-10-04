#ifndef TREE_H
#define TREE_H

typedef char data_t;

typedef struct node {
	data_t data;
	struct node *left;
	struct node *right;
} bitree;

bitree *tree_create();
void preorder(bitree *r);
void inorder(bitree *r);
void postorder(bitree *r);
void layerorder(bitree *r);

#endif
