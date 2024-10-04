#include <stdio.h>

int main(){
	FILE *fp;
	int year = 2024, month = 6, day = 1;
	char buf[100] = {0};

	fp = fopen("myfile2.txt", "w");
	if(!fp){
		perror("fopen");
		return -1;
	}

	fprintf(fp, "%d-%d-%d\n", year, month, day);

	sprintf(buf, "%d-%d-%d\n", year, month, day);
	
	printf("%s", buf);

	return 0;
}
