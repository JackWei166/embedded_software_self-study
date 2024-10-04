#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define N 64
#define READ 0
#define WRITE 1

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short *array;
	struct seminfo *__buf;
};    //xxx if什么的不用，struct union什么的还是需要”；“的！！！

void init_sem(int semid, int s[], int n);   //xxx 进程 -t key -t sem shm 无（文件 无）
void pv(int semid, int num, int op);

int main(void){
	key_t key;
	pid_t pid;
	int shmid, semid;
	char *shmaddr, *p, *q;
	int s[2] = {0, 1};

	if ((key = ftok(".", 'a')) < 0) {   //xxx '' "" 不一样！！！
		perror("ftok");
		return 1;
	}

	if ((shmid = shmget(key, N, 0666 | IPC_CREAT)) < 0) {
		perror("shmget");
		return 1;
	}

	if ((shmaddr = (char *)shmat(shmid, NULL, 0)) == (char *)(-1)) {
		perror("shmat");
		goto _error1;
	}

	if ((semid = semget(key, 2, 0666 | IPC_CREAT)) < 0) {
		perror("semget");
		goto _error2;
	}

	init_sem(semid, s, 2);

	if ((pid = fork()) < 0 ) {
		perror("fork");
		goto _error2;
	} else if (pid == 0) {
		while (1) {   //xxx 需要一直操作，别忘了循环
			pv(semid, READ, -1);
			p = q = shmaddr;
			while (*q) {
				if (*q != ' ') {
					*p++ = *q;
				}
				q++;
			}
			*p = '\0';   //xxx 处理字符串最后别忘了添\0  并且，是给*p添！！！
			printf("%s", shmaddr);
			pv(semid, WRITE, 1);
		}
	} else {
		while (1) {
			pv(semid, WRITE, -1);
			printf("input:");
			fgets(shmaddr, N, stdin);
			if (strcmp(shmaddr, "quit\n") == 0) break;
			pv(semid, READ, 1); 
		}
		kill(pid, SIGUSR1);   //xxx 默认应该就是结束子进程，共享内存，信号灯集的引用都减一；下面父进程删除操作才有效；
	}   //xxx 父进程打算退出，同时子进程不能自动退的话，就得这样了

_error2:
	semctl(semid, 0, IPC_RMID);

_error1:
	shmctl(shmid, IPC_RMID, NULL);

	return 0;
}


void init_sem(int semid, int s[], int n){
	union semun myun;
	int i;

	for(i = 0; i < n; i++){
		myun.val = s[i];
		semctl(semid, i, SETVAL, myun);
	}
}

void pv(int semid, int num, int op){
	struct sembuf buf;

	buf.sem_num = num;
	buf.sem_op = op;
	buf.sem_flg = 0;

	semop(semid, &buf, 1);
}
