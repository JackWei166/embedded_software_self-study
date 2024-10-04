#include <stdio.h>
#include "tree.h"


int main(int argc, char *argv[]){
	bitree *r;

	r = tree_create();
	if(!r){
		printf("create tree failed.\n");
		return -1;
	}

	preorder(r);
	puts("");

	inorder(r);
	puts("");

	postorder(r);
	puts("");

	layerorder(r);
	puts("");

	return 0;
}
