#include <stdio.h>
#include "linkqueue.h"
#include "sqstack.h"

int check_queue(linkqueue *lq);

int main(int argc, char *argv[]){
	linkqueue *lq;   //xxx 除了linklist ，listnode，sqstack，linkstack，sequeue，linkqueue，基本没有*定义吧
	sqstack *s_min, *s_five, *s_hour;
	int min = 0, value, t, i;

	lq = queue_create();
	if(!lq){
		printf("create queue failed.\n");
		return -1;
	}

	for(i = 1; i <= 27; i++){
		enqueue(lq, i);
	}

	s_min = stack_create(4);
	if(!s_min){
		printf("create min stack failed.\n");
		return -1;
	}

	s_five = stack_create(11);
	if(!s_five){
		printf("create five stack failed.\n");
		return -1;
	}

	s_hour = stack_create(11);   //xxx 觉得创建空间后返回地址，为了节省资源空间
	if(!s_hour){
		printf("create hour stack failed.\n");
		return -1;
	}


	while(1){
		min++;

		value = dequeue(lq);
		
		if(!stack_full(s_min)){
			stack_push(s_min, value);
		} else {
			while(!stack_empty(s_min)){
				t = stack_pop(s_min);
				enqueue(lq, t);
			}
			if(!stack_full(s_five)){
				stack_push(s_five, value);
			} else {
				while(!stack_empty(s_five)){
					t = stack_pop(s_five);
					enqueue(lq, t);
				}
				if(!stack_full(s_hour)){
					stack_push(s_hour, value);
				} else {
					while(!stack_empty(s_hour)){
						t = stack_pop(s_hour);
						enqueue(lq, t);
					}
					enqueue(lq, value);
					if(check_queue(lq)){
						break;
					}
				}
			}
		}

	}

	printf("total :%d\n", min);

	return 0;
}

int check_queue(linkqueue *lq){
	linklist p;

	if(!lq){
		printf("Lq is null.\n");
		return -1;
	}

	p = lq->front->next;

	while(p && p->next){
		if(p->data < p->next->data){
			p = p->next;
		} else {
			return 0;
		}
	}

	return 1;
}
