#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define N 32

int main(void){
	int pfd[2];
	pid_t pid1, pid2;
	char buf[N];

	if (pipe(pfd) < 0) {   //xxx 括号前后有空格的！！！c现代，华清老师都有，很久没注意
		perror("pipe");
		return 1;
	}

	if ((pid1 = fork()) < 0) {
		perror("fork pid1");
		return 1;
	} else if(pid1 == 0) {
		strcpy(buf, "I an process1");
		write(pfd[1], buf, N);
	} else {
		if ((pid2 = fork()) < 0) {
			perror("fork pid2");
			return 1;
		} else if (pid2 == 0) {
			//sleep(1);
			strcpy(buf, "I am process2");
			write(pfd[1], buf, N);
		} else {
			wait(NULL);
			read(pfd[0], buf, N);
			printf("%s\n", buf);

			wait(NULL);
			read(pfd[0], buf, N);			
			printf("%s\n", buf);
		}
	}
	return 0;
}
