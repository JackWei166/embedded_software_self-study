#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "mychar.h"

int main(int args, char *argv[]){
	int fd;
	char buf[8];
	int max, cur;
	int ret;

	if (args < 2) {
		printf("The argument is few.\n");
		return 1;
	}

	fd = open(argv[1], O_RDWR);   //xxx 增加操作注意改权限
	if (fd < 0) {
		printf("open %s failed\n", argv[1]);
		return 2;
	}

	ret = read(fd, buf, 8);
	if (ret < 0) {
		printf("read data failed\n");
	} else {
		printf("buf = %s\n", buf);
	}

	close(fd);
	fd = -1;

	return 0;
}
