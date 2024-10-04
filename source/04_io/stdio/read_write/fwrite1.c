#include <stdio.h>

int main(int argc, const char *argv[]){
	FILE *fp;

	struct score {
		int no;
		char name[50];
		int score;
	} s[] = {{1, "zhangsan", 90}, {2, "wangwu", 91}};

	fp = fopen(argv[1], "w");
	if(!fp){
		perror("fopen");
		return -1;
	}

	fwrite(s, sizeof(struct score), 2, fp);

	return 0;
}
