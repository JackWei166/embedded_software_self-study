#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define N 32

char buf[N];
sem_t sem;

void *function(void *arg);   //xxx 哦，知道为什么一般函数前面，顺序一般是，预处理 文件包含 宏定义，类型定义，变量声明，函数声明了，依赖关系！
							 //xxx 数据是逐渐丰富的

int main(void){
	pthread_t a_pthread;

	if(sem_init(&sem, 0, 0) < 0){
		perror("sem_init");
		return 1;   //xxx main中注意，return不能-1，状态吗中没有负值；看着那老师给的例子都错了
	}

	if(pthread_create(&a_pthread, NULL, function, NULL) < 0){
		perror("pthread_create");
		return 1;
	}

	printf("Please input any chars, 'quit' will quit:");
	while(1){
		fgets(buf, N, stdin);
		if(strncmp(buf, "quit", 4) == 0) break;
		sem_post(&sem);
	}

	return 0;
}

void *function(void *arg){
	while(1){
		sem_wait(&sem);
		printf("You input %d char.\n", strlen(buf));
	}
}   //xxx return与否，觉得这里暂时就随缘了，需要返就返，有问题一般编译器会提醒
