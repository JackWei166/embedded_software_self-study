#include <stdio.h>
#include <string.h>

#define N 32

struct stu {
	int no;
	char name[N];
	int score;
} s[5] = {{1, "s1", 93}, {2, "s2", 89}, {3, "s3", 92}};


void print_info(struct stu *p, int n){
	int i;
	
	for(i = 0; i < n; i++){
		printf("no: %d, name: %s, score: %d\n", (*(p+i)).no, (*(p+i)).name, (*(p+i)).score);
		p++;
	}
}

int main(int argc, char *argv[]){
	print_info(s, sizeof(s)/sizeof(s[0]));

	return 0;
}
