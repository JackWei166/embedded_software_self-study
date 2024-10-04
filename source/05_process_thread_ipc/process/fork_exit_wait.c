#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid;
	int status;

	if((pid = fork()) < 0){   //xxx 成功的话，会有两个进程从此处开始往下运行
		perror("fork");
		return -1;
	} else if(pid == 0){
		printf("child process:my pid is %d.\n", getpid());
		//exit(255);   //xxx 不要超过255，否则会溢出！！！
		return 254;    //xxx return在哪个函数就终止谁，exit在哪都终止。 在main函数二者等价，但应该就不能return-1了
		printf("never bedisplayed");
	} else {
		printf("parent process:my pid is %d.\n", getpid());
	}
	
	wait(&status);   //xxx 要获取exit返回的值，还得借助宏来弄，详见课件
	if(WIFEXITED(status)){
		printf("status: %x\n", status);
		printf("child process return %d.\n", WEXITSTATUS(status));
	}
	
	return 0;
}
