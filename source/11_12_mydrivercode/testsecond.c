#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(int args, char *argv[]){
	int fd;
	int sec;

	if (args < 2) {
		printf("The argument is few.\n");
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		printf("open %s failed\n", argv[1]);
		return 2;
	}

	sleep(3);

	read(fd, &sec, 8);
	printf("buf = %d\n", sec);

	close(fd);
	fd = -1;

	return 0;
}
