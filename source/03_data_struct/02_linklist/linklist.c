#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"


linklist list_create(){
	linklist H;

	H = (linklist)malloc(sizeof(listnode));
	if(H == NULL){
		printf("malloc failed.\n");   //xxx  vim搜索替换\n要再加上\的
		return H;
		}

	H->data = 0;
	H->next = NULL;

	return H;
}

int list_tail_insert(linklist H, data_t value){
	linklist q, p;

	if(!H){
		printf("H is null\n.\n");
		return -1;
	}

	p = (linklist)malloc(sizeof(listnode));
	if(!p){
		printf("malloc failed.\n");
		return -1;
	}
	p->data = value;
	p->next = NULL;
	
	q = H;
	while(q->next){   //xxx !q  判不等于0，就直接放这儿；等于0，就加个！再放。 恩，一个知识忙点
		q = q->next;  //xxx 因为要找next为空的节点，所以要从next判断
	}

	q->next = p;

	return 0;
}

linklist list_get(linklist H, int pos){
	int i;
	linklist p;

	if(!H){
		printf("H is null\n.");
		return NULL;
	}

	if(pos == -1){
		return H;
	}

	if(pos < -1){
		printf("pos is invalid.\n");
		return NULL;
	}

	p = H;
	i = -1;
	while(i < pos){
		p = p->next;
		if(!p){
			printf("pos is invalid.\n");
			return NULL;
		}
		i++;
	}

	return p;
}

int list_insert(linklist H, data_t value, int pos){
	linklist p, q;

	if(!H){
		printf("H is null\n.");
		return -1;
	}

	p = (linklist)malloc(sizeof(listnode));
	if(!p){
		printf("malloc failed.\n");
		return -1;
	}
	p->data = value;
	p->next = NULL;

	q = list_get(H, pos-1);
	if(!q){
		printf("get listnode failed.\n");
		return -1;
	}

	p->next = q->next;
	q->next = p;
	
	return 0;
}

int list_delete(linklist H, int pos){
	linklist p, q;

	if(!H){
		printf("H is null\n.");
		return -1;
	}

	p = list_get(H, pos-1);
	if(!p){
		printf("get listnode failed.\n");
		return -1;
	}
	if(!(p->next)){
		printf("pos is invalid.\n");
		return -1;
	}
	
	q = p->next;
	p->next = q->next;

	printf("delete: %d\n", q->data);
	free(q);
	q = NULL;

	return 0;
}

int list_show(linklist H){
	linklist p;

	if(!H){
		printf("H is null\n.");
		return -1;
	}

	p = H;
	while(p->next){    //xxx !p  同上；觉得还有，这个链表头不放数据，所以，从next开始吧
		printf("%d ", p->next->data);   //xxx p->data  
		p = p->next;
	}
	puts("");

	return 0;
}

linklist list_free(linklist H){
	linklist p;

	if(!H){
		printf("H is null\n.");
		return NULL;
	}

	printf("free:");
	while(H){
		p = H;
		H = H->next;

		printf("%d ", p->data);
		free(p);
		p = NULL;
	}
	puts("");
	
	return NULL;
}

int list_reverse(linklist H){
	linklist p, q;

	if(!H){
		printf("H is null\n.");
		return -1;
	}

	if(!(H->next) || !(H->next->next)){
		return 0;
	}

	p = H->next->next;
	H->next->next = NULL;   //xxx  一开始没写这行，导致12循环打印；既然要要切断重新组队，就得有NULL赋值吧
	while(p){
		q = p;
		p = p->next;

		q->next = H->next;
		H->next = q;
	}

	return 0;
}

linklist list_adjmax(linklist H, data_t *value){
	linklist p, q, r;
	int sum;

	if(!H){
		printf("H is null\n.");
		return NULL;
	}

	if(!(H->next) || !(H->next->next)){
		printf("less 2 data.\n");
		return NULL;   //xxx  排不了不符合要求的，就是0个数、1个数的；觉得老师给的代码不太好
	}   //xxx  尽量每天不写代码了，统计一下行数

	p = H->next;
	q = H->next->next;
	r = p;
	sum = p->data + q->data;

	while(q->next){
		p = p->next;
		q = q->next;
		if(sum < p->data + q->data){
			sum = p->data + q->data;
			r = p;
		}
	}

	*value = sum;

	return r;
}
