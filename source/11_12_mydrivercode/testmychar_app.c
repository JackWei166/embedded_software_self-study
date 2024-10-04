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

	if (args < 2) {
		printf("The argument is few.\n");
		return 1;
	}

	fd = open(argv[1], O_RDWR);   //xxx 增加操作注意改权限
	if (fd < 0) {
		printf("open %s failed\n", argv[1]);
		return 2;
	}

	ioctl(fd, MYCHAR_IOCTL_GET_MAXLEN, &max);
	printf("max len is %d\n", max);

	write(fd, "hello", 6);

	ioctl(fd, MYCHAR_IOCTL_GET_CURLEN, &cur);
	printf("cur len is %d\n", cur);

	read(fd, buf, 8);
	printf("buf = %s\n", buf);

	close(fd);
	fd = -1;

	return 0;
}
