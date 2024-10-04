#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define N 64

int main(){
	FILE *fp;
	time_t t;
	struct tm *lt;
	int line = 0;
	char buf[N];

	fp = fopen("myfile3.txt", "a+");
	if(!fp){
		perror("fopen");
		return -1;
	}

	while(fgets(buf, N, fp) != NULL){
		if(buf[strlen(buf)-1] == '\n'){
			line++;
		}
	}

	while(1){
		time(&t);
		lt = localtime(&t);
		fprintf(fp, "%d, %d-%02d-%02d %02d:%02d:%02d\n", ++line, lt->tm_year+1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);
		fflush(fp);
		sleep(1);
	}

	fclose(fp);

	return 0;
}
