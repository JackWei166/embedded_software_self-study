#include <stdio.h>


int main(int argc, char *argv[]){
	FILE *fp;
	int count = 0, c, a;

	fp = fopen(argv[1], "r");
	if(!fp){
		perror("fopen");
		return -1;
	}

	while((c = fgetc(fp)) != EOF){   //xxx 去了赋值也可以吗？
		count++;
		a = c;
	}

	printf("total:%d\n", count);
	printf("end char:%d\n", a);   //xxx默认每行末尾有换行符，不要忘了

	return 0;
}
