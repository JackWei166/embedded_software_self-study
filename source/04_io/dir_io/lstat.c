#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[]){
	struct stat fs;
	struct tm *lt;
	int n;

	if(argc < 2){
		printf("Usage: %s <file>\n", argv[1]);
		return -1;
	}

#if 0
	dp = opendir(argv[1]);
	if(dp == NULL){
		perror("opendir");
		return -1;
	}
#endif

	lstat(argv[1], &fs);

	switch(fs.st_mode & S_IFMT){
	case S_IFREG:
		printf("-");
		break;
	case S_IFDIR:
		printf("d");
		break;
	}

	//傻了，if当成for了！！！
	for(n = 8; n >= 0; n--){   //xxx 位置还有01决定显示什么字符，所以要根据次拆分问题吧
		if(fs.st_mode & (1 << n)){
			switch(n%3){
			case 0:
				printf("x");
				break;
			case 1:
				printf("w");
				break;
			case 2:
				printf("r");
				break;
			}
		} else {
			printf("-");
		}
	}

	printf(" %lu", fs.st_size);

	lt = localtime(&fs.st_mtime);
	printf(" %d-%02d-%02d", lt->tm_year+1900, lt->tm_mon+1, lt->tm_mday);

	printf(" %s\n", argv[1]);

	return 0;
}
