#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 32

int main(void){
	int pfd[2], status;
	pid_t pid;
	char buf[N];

	if (pipe(pfd) < 0) {
		perror("pipe");
		return 1;
	}

	close(pfd[0]);

	if ((pid = fork()) < 0) {
	} else if (pid == 0) { 
		write(pfd[1], buf, N);
	} else {
		wait(&status);
		printf("status:%x\n", status);
	}

	return 0;
}   //xxx kill -l 可以看信号及其代号；sigpipe 13 d
