#include <semaphore.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>

#define N 32

char buf[N];
sem_t sem_r, sem_w;

void *function(void *arg);   
							 

int main(void){
	pthread_t a_pthread;

	if(sem_init(&sem_r, 0, 0) < 0){
		perror("sem_r_init");
		return 1;   
	}

	if(sem_init(&sem_w, 0, 1) < 0){
		perror("sem_w_init");
		return 1; 
	}
	if(pthread_create(&a_pthread, NULL, function, NULL) < 0){
		perror("pthread_create");
		return 1;
	}

	printf("Please input any chars, 'quit' will quit:");
	while(1){
		sem_wait(&sem_w);
		fgets(buf, N, stdin);
		if(strncmp(buf, "quit", 4) == 0) break;
		sem_post(&sem_r);
	}

	return 0;
}

void *function(void *arg){
	while(1){
		sem_wait(&sem_r);
		printf("You input %d char.\n", strlen(buf));
		sem_post(&sem_w);
	}
}
