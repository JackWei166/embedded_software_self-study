#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define N 32

int main(void){
	int pfd;
	char buf[N];

	if ((pfd = open("myfifo", O_RDONLY)) < 0) {
		perror("open");
		return 1;
	}


	while (read(pfd, buf, N) > 0) {   //xxx 非0 返回大于0！ 0 存在，阻塞；0 不存在 返回0（仔细探究起成败及其由来很好理解）
		printf("wrote %d chars\n", strlen(buf));
	}

	close(pfd);

	return 0;
}
