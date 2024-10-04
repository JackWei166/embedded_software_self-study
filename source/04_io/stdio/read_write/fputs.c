#include <stdio.h>

int main(int argc, char *argv[]){
	FILE *fp;
	char buf[] = "Hello, world!";

	fp = fopen(argv[1], "a");
	if(!fp){
		perror("fopen");
		return -1;
	}

	fputs(buf, fp);

	return 0;
}
