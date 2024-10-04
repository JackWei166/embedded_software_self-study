#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *fps, *fpd;
	char c;

	fps = fopen(argv[1], "r");
	if(!fps){
		perror("fopen fps");
		return -1;
	}

	fpd = fopen(argv[2], "w");
	if(!fpd){
		perror("fopen fpd");
		return -1;
	}

	while((c = fgetc(fps)) != EOF){
		fputc(c, fpd);
	}

	fclose(fps);
	fclose(fpd);

	return 0;
}
