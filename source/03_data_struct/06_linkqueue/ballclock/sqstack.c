#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sqstack.h"

sqstack *stack_create(int len){
	sqstack *S;

	S = (sqstack *)malloc(sizeof(sqstack));
	if(!S){
		printf("malloc sqstack failed.\n");   //xxx 只要printf，最后都要考虑换行！！！
		return NULL;
	}

	S->data = (data_t *)malloc(len*sizeof(data_t));
	if(!S->data){
		free(S);
		printf("malloc data failed.\n");
		return NULL;
	}

	memset(S->data, 0, len*sizeof(data_t));
	S->maxlen = len;
	S->top = -1;

	return S;
}

int stack_push(sqstack *S, data_t value){   //xxx 恩，有意义的字符（正则）、控制字符等，要显示，得加上反斜杠
	

	if(!S){
		printf("stack is null\n");
		return -1;
	}

	if(S->top == S->maxlen - 1){
		printf("stack is full\n");
		return -1;
	}

	S->top++;
	S->data[S->top] = value;

	return 0;
}

int stack_empty(sqstack *S){
	if(!S){
		printf("stack is null\n");
		return -1;
	}

	return S->top == -1 ? 1 : 0;    //xxx return后可以加表达式，所以不加括号没问题
}

int stack_full(sqstack *S){
	if(!S){
		printf("stack is null\n");
		return -1;
	}
	
	return S->top == S->maxlen-1 ? 1 : 0; 
}

data_t stack_pop(sqstack *S){   //xxx 哦，觉得应该是返回弹出的数了，再返回失败标志可能重合，这里就没有设置；那就得应用的时候注意了
	S->top--;	
	return S->data[S->top+1];
}

data_t stack_top(sqstack *S){
	if(!S){
		printf("stack is null\n");
		return -1;
	}

	if(stack_empty(S)){   //xxx 觉得像这种返回数据的，就尽量别判断空满之类的了，觉得可能会混淆(要判断在应用测试里面判断）
		printf("stack is empty\n");
		return -1;
	}

	return S->data[S->top];
}

int stack_clear(sqstack *S){
	if(!S){
		printf("stack is null\n");
		return -1;
	}
	
	S->top = -1;

	return 0;
}

int stack_free(sqstack *S){
	if(!S){
		printf("stack is null\n");
		return -1;
	}

	if(S->data){   //xxx 试验一下，free NULL也可以
		free(S->data);
		S->data = NULL;
	}

	free(S);   //xxx 前面已经检查非空了，这里就不用了；先释放里面的在释放外面的
	S = NULL;

	return 0;
}
