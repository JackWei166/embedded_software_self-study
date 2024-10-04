#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>
#include <stdlib.h>

int main(){
	pid_t pid;
	int status;

	pid = fork();
	if(pid < 0){
		printf("fork p1");
	} else if(pid == 0){
		if(execl("/bin/ls", "ls", "-a", "-l", "/etc", NULL) < 0){   //xxx exec成功后，后面的代码就不执行了！要还想执行，你得在子程序里面来！
			perror("execl");
			return -1;
		}
	}

	wait(NULL);   //xxx 尽可能要有，结束不会自动回收，让系统回收也得等时间
	              //xxx
				  //像我这种，想一个子进程弄完另一个弄，可以调完子进程，随后就wait回收，避免干扰

	puts("");

	pid = fork();   //xxx 创建进程线程后，首先考虑用不用同步互斥机制;这里已开始没用，一个运行就打断另一个运行了！
	if(pid < 0){
		printf("fork p2");
	} else if(pid == 0){
		if(execlp("ls", "ls", "-a", "-l", "/etc", NULL) < 0){
			perror("execlp");
			return -1;
		}

		exit(66);
	}   //xxx main结束，没有return、exit，程序会自己调用exit（0）；所以，暂定不返回特别的数值就不调用了

	wait(&status);
	puts("");
	printf("status is %x\n", status);
	printf("p2 return %d\n", WEXITSTATUS(status));   //xxx return在哪个函数就终止谁，exit在哪都终止
													 //xxx
													 //对对对，execlp执行后下面就不执行了！父进程这样，子进程也这样的！(要实验还得去别的地方）

	return 0;
}
