#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define N 64

int main(int argc, char *argv[]){
	int fd, n = 0, total = 0;
	char buf[N];

	if(argc < 2){
		printf("Usage: %s <file>\n", argv[0]);
		return -1;
	}

	fd = open(argv[1], O_RDONLY);
	if(fd < 0){
		perror("open");
		close(fd);   //xxx 对于错误处理，不是第一次考虑释放之前的创建！！！
		return -1;
	}

	while((n = read(fd, buf, N)) > 0){
		total += n;
	}

	if(n < 0){   //xxx read即使在while内了，也要考虑错误处理！！！
		perror("read");
		close(fd);
		return -1;
	}

	printf("total:%d\n", total);   //xxx 犯糊涂了，输出总数，输出了加数！！！

	close(fd);

	return 0;
}
