#include <stdio.h>
#include <fcntl.h>

int main(){
	int fd;

	fd = open("1.txt", O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if(fd < 0){
		perror("open");
		return -1;
	}

	close(fd);

	return 0;
}
