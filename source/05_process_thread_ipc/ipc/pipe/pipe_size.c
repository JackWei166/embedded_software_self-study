#include <unistd.h>
#include <stdio.h>

#define N 32

int main(void){
	int pfd[2], count = 0;
	char buf[N];

	if(pipe(pfd) < 0 ){
		perror("pipe");
		return 1;
	}

	while (1) {
		write(pfd[1], buf, N);
		printf("%dk bytes have been written.\n", ++count);   //xxx 打印，格式串最后都考虑换行；这里不换行，到1017?2017？不是2048；应该是标准输出流是有缓冲区的，换行或者满了输出.  但是我看老师没换行，怎么一点都没打印？
	}

	return 0;
}

