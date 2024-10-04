#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int main(void){
	pid_t pid;
	char *arg[] = {"ls", "-a", "-l", "/etc", NULL};

	pid = fork();
	if(pid < 0){
		printf("fork p1");
	} else if(pid == 0){
		if(execv("/bin/ls", arg) < 0){   
			perror("execl");
			return -1;
		}
	}

	wait(NULL);   
	              
	puts("");

	pid = fork();   
	if(pid < 0){
		printf("fork p2");
	} else if(pid == 0){
		if(execvp("ls", arg) < 0){
			perror("execlp");
			return -1;
		}
	}   

	wait(NULL);
													 
	return 0;
}
