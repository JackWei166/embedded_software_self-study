#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

int main(int args, char *argv[]){
	int fd;

	if (args < 2) {
		printf("The argument is few.\n");
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		printf("open %s failed\n", argv[1]);
		return 2;
	}

	while (1) {
	}

	close(fd);
	fd = -1;

	return 0;
}
