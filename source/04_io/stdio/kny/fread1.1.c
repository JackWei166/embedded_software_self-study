#include <stdio.h>

#define N 10

int main(int argc, char *argv[]){
	FILE *fp;
	int s[N], i;

	fp = fopen("myfile2.txt", "r");
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
	puts("");

	return 0;
}
