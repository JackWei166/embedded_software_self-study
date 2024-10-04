#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *fp;
	int i;

	fp = fopen(argv[1], "w");
	if(!fp){
		perror("fopen");
		return -1;
	}

	for(i = 'a'; i <= 'z'; i++){
		fputc(i, fp);   //xxx 自己写入就有换行符了，用fputc的不加就没有
	}

	fclose(fp);

	return 0;
}
