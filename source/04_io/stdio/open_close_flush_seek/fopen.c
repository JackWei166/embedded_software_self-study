#include <stdio.h>

#include <string.h>
#include <errno.h>   //xxx 只要语言库，不管std不，都得尖括号

int main(int argc, char *argv[]){
	FILE *fp;

	fp = fopen("myfile1.txt", "r");   //xxx 读不会创建 +也不行
	if(!fp){
		//printf("open file failed.\n");
		//printf("fopen:%s\n", strerror(errno));
		perror("fopen");   //xxx 简洁好用，觉得可以常用
		return -1;
	}

	fclose(fp);

	return 0;
}
