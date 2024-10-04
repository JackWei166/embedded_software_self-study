#include <stdio.h>
#include <string.h>

#define N 32

struct stu {
	int no;
	char name[N];
	int score;
} s[5] = {{1, "s1", 93}, {2, "s2", 89}, {3, "s3", 92}};

int main(int argc, char *argv[]){
	int i, n;

	n = sizeof(s) / sizeof(s[0]);

	for(i = 0; i < n; i++){
		printf("no: %d, name: %s, score: %d\n", s[i].no, s[i].name, s[i].score);
	}

	return 0;
}
