#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	int fd;
	char buf[] = "t";

	if(argc < 2){
		printf("Usage: %s <file>\n", argv[1]);
		return -1;
	}

	fd = open(argv[1], O_WRONLY|O_CREAT, 0666);
	if(fd < 0){
		perror("open");
		return -1;
	}

	lseek(fd, 0, SEEK_END);

	write(fd, buf, strlen(buf));

	close(fd);

	return 0;
}
