#include <stdio.h>

#define N 10

int main(int argc, char *argv[]){
	FILE *fp;
	int numbers[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	fp = fopen("myfile4.txt", "wb");   //xxx 觉得很可能在文件格式上了，回头再说吧
	if(!fp){
		perror("fopen");
		return -1;
	}

	fwrite(numbers, sizeof(int), N, fp); 

	fclose(fp);

	return 0;
}
