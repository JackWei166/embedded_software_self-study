#include <stdio.h>

#define N 10

int main(int argc, char *argv[]){
	FILE *fp;
	int s[N], i;

	fp = fopen("myfile4.txt", "rb");
	if(!fp){
		perror("fopen");
		return -1;
	}

	if(fread(s, sizeof(int), N, fp) == EOF){
		perror("fread");
		return -1;
	}

	for(i = 0; i < N; i++){
		printf("%d ", s[i]);
	}
	puts("");   //xxx 使用fread fwrite ，尽量保证对应文件，是相同的打开方式和类型函数处理过的；
                //xxx 就数组名接收使用就行，直接打开文件可能乱码
	return 0;
}
