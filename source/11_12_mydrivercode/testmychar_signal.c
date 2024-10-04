#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "mychar.h"
#include <sys/select.h>
#include <sys/time.h>
#include <errno.h>
#include <signal.h>

int fd;

void sigio_handler(int signo);

int main(int args, char *argv[]){
	//int fd;
	int flg;

	if (args < 2) {
		printf("The argument is few.\n");
		return 1;
	}

	fd = open(argv[1], O_RDWR);   //xxx 增加操作注意改权限
	if (fd < 0) {
		printf("open %s failed\n", argv[1]);
		return 2;
	}
	
	fcntl(fd, F_SETOWN, getpid());

	flg = fcntl(fd, F_GETFL);
	flg |= FASYNC;
	fcntl(fd, F_SETFL, flg);

	signal(SIGIO, sigio_handler);

	while (1) {
	}

	close(fd);
	fd = -1;

	return 0;
}

void sigio_handler(int signo){
	char buf[8];

	read(fd, buf, 8);
	printf("buf = %s\n", buf);
}
