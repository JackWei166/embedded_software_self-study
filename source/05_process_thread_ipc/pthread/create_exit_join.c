#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define N 128

char message[N] = "Hello, world!";

void *pthread_func(void *arg);

int main(void){
	pthread_t a_pthread;
	void *result;

	if(pthread_create(&a_pthread, NULL, pthread_func, NULL) < 0){   //xxx 函数参数，出入必须void *,规定输入的就是这种类型
		perror("pthread_create");
		return -1;
	}

	pthread_join(a_pthread, &result);

	printf("result:%s\n", (char *)result);
	printf("message:%s\n", message);

	return 0;
}   //xxx 涉及线程的程序运行，gcc别忘lpthread，否则报错 未定义的引用

void *pthread_func(void *arg){

	strcpy(message, "marked by pthread_func");
:
	pthread_exit("done");
}
