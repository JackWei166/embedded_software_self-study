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

int main(int args, char *argv[]){
	int fd;
	char buf[8];
	int max, cur;
	int ret;
	fd_set rfds;

	if (args < 2) {
		printf("The argument is few.\n");
		return 1;
	}

	fd = open(argv[1], O_RDWR);   //xxx 增加操作注意改权限
	if (fd < 0) {
		printf("open %s failed\n", argv[1]);
		return 2;
	}

	while (1) {
		FD_ZERO(&rfds);
		FD_SET(fd, &rfds);

		ret = select(fd + 1, &rfds, NULL, NULL, NULL);
		if (ret < 0) {
			if (errno == EINTR) {
				continue;
			} else {
				printf("select error\n");
				break;
			}
		}

		if (FD_ISSET(fd, &rfds)) {
			read(fd, buf, 8);
			printf("buf = %s\n", buf);
		}
	}

	close(fd);
	fd = -1;

	return 0;
}
