#include <stdio.h>

int main(){
	FILE *fp;

	fp = fopen("myfile1.txt", "r");
	if(!fp){
		perror("fopen");
		return -1;
	}

	fseek(fp, 0, SEEK_END);

	printf("length is %ld\n", ftell(fp));

	return 0;
}
