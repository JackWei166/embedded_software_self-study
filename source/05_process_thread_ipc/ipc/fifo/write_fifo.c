#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define N 32

int main(void){
	int pfd;
	char buf[N];

	if ((pfd = open("myfifo", O_WRONLY)) < 0) {
		perror("open");
		return 1;
	}

	while (1) {
		fgets(buf, N, stdin);
		if (strcmp(buf, "quit\n") == 0) break;
		write(pfd, buf, N);
	}
	
	close(pfd);

	return 0;
}
