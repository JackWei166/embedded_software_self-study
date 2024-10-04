#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define N 64

int main(int argc, char *argv[]){
	int fds, fdt, n;
	char buf[N];

	if(argc < 3){
		printf("Usage: %s <src file> <dst file>\n", argv[0]);
		return -1;
	}

	fds = open(argv[1], O_RDONLY);
	if(fds < 0){
		perror("open src file");
		return -1;
	}

	fdt = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666);
	if(fdt < 0){
		perror("open dst file");
		close(fds);
		return -1;
	}

	while((n = read(fds, buf, N)) > 0){
		write(fdt, buf, n);
	}

	if(n < 0){
		printf("read fds file failed\n");
		close(fds);
		close(fdt);
		return -1;
	}

	close(fds);
	close(fdt);

	return 0;
}
