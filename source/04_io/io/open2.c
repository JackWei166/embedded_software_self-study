#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int main(){
	int fd;

	//fd = open("1.txt", O_WRONLY|O_CREAT|O_EXCL, 0666);
	fd = open("3.txt", O_WRONLY|O_CREAT|O_EXCL, 0666);
	if(fd < 0){
		if(errno == EEXIST){
			perror("exist error");
			return -1;
		} else {
			perror("other error");
			return -1;
		}
	}

	close(fd);

	return 0;
}
