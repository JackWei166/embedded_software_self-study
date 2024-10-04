#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "linkqueue.h"



bitree *tree_create(){
	bitree *r;
	char ch;

	scanf(" %c", &ch);   //xxx scanf连续输入，注意吃回车的问题！！！ 匹配前0到多个字符，匹配好后就结束，所以连续几个字符应该没问题
	if(ch == '#'){   //xxx 暂时出现问题，可以对比老师给的代码；可以让kimi检查 先小范围再大范围；可以让kimi写对比；考虑gpt4看看（这个就是kimi写对比出来的；python入门实践书籍作者说得对，很多都是简单问题导致停滞
		return NULL;
	}

	r = (bitree *)malloc(sizeof(bitree));
	if(!r){
		printf("malloc bitree failed.\n");
		return NULL;
	}
	
	r->data = ch;
	r->left = tree_create();
	r->right = tree_create();

	return r;
}

void preorder(bitree * r){
	if(!r){
		return;
	}

	printf("%c ", r->data);

	preorder(r->left);

	preorder(r->right);
}

void inorder(bitree * r){
	if(!r){
		return;
	}

	inorder(r->left);

	printf("%c ", r->data);

	inorder(r->right);
}

void postorder(bitree * r){
	if(!r){
		return;
	}

	postorder(r->left);

	postorder(r->right);

	printf("%c ", r->data);
}

void layerorder(bitree * r){
	linkqueue *lq;

	if(!r){
		printf("r is null.\n");
		return;
	}

	lq = queue_create();
	if(!lq){
		printf("create queue failed.\n");
		return;
	}

	enqueue(lq, r);

	while(!queue_empty(lq)){
		r = dequeue(lq);   //xxx 备份处理，涉及到取地址，才可能涉及到改变类型值
		
		printf("%c ", r->data);

		if(r->left){
			enqueue(lq, r->left);
		}
		if(r->right){
			enqueue(lq,r->right);
		}
	}
}
