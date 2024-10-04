#include <pthread.h>
#include <stdio.h>

int value1 = 0;
int value2 = 0;
pthread_mutex_t mutex;

void *function(void *arg);

int main(void){
	pthread_t a_pthread;
	int count = 0;

	if(pthread_mutex_init(&mutex, NULL) < 0){
		perror("pthread_mutex_init");
		return 1;
	}

	if(pthread_create(&a_pthread, NULL, function, NULL) < 0){
		perror("pthread_create");
		return 1;
	}

	//for(i = 0; i < 10000; i++){
	while(1){
		count++;
#if _LOCK_
		pthread_mutex_lock(&mutex);
#endif
		value1 = count;
		value2 = count;
#if _LOCK_
		pthread_mutex_unlock(&mutex);
#endif
	}
	return 0;
}

void *function(void *arg){
#if _LOCK_
	pthread_mutex_lock(&mutex);
#endif
	while(1){
		if(value1 != value2){   //xxx 这儿也得while循环！！！
			printf("value1 = %d, value2 = %d\n", value1, value2);
		}
	}
#if _LOCK_
	pthread_mutex_unlock(&mutex);
#endif
	return NULL;
}
