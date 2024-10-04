#include <stdio.h>

int main(){
	FILE *fp;

	fp = fopen("myfile1.txt", "a");
	if(!fp){
		perror("fopen");
		return -1;
	}

	fseek(fp, 0, SEEK_END);

	fputc('b', fp);
	fflush(fp);

	while(1);

	fclose(fp);

	return 0;
}
