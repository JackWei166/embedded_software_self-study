#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define N 20

int main(int argc, char *argv[]){
	int fd;
	char buf[N];

	if(argc < 2){
		printf("Usage: %s <file>\n", argv[0]);
		return -1;
	}

	fd = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if(fd < 0){
		perror("open");
		return -1;
	}

	while(fgets(buf, N, stdin) != NULL){
		if(strcmp(buf, "quit\n") == 0){
			break;
		} else {
			write(fd, buf, strlen(buf));
		}
	}

	close(fd);

	return 0;
}
