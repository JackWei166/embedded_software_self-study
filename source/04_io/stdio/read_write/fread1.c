#include <stdio.h>

#define N 10

int main(int argc, char *argv[]){
	FILE *fp;
	int s[N], i;
	int numbers[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	fp = fopen("myfile.bin", "w+b");   //xxx 觉得很可能在文件格式上了，回头再说吧
	if(!fp){
		perror("fopen");
		return -1;
	}

#if 0
	for(i = 0; i < N; i++){
		fprintf(fp, "%d ", numbers[i]);
	}
#endif

	fwrite(numbers, sizeof(int), N, fp);   //xxx 也不行，再说吧，回头再说

	if(fread(s, sizeof(int), N, fp) == EOF){
		perror("fread");
		return -1;
	}

	for(i = 0; i < N; i++){
		printf("%d ", s[i]);
	}
	puts("");

	return 0;
}
