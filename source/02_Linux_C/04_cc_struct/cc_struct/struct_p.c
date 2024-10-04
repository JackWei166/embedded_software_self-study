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
	struct stu *p;

	p = s;

	n = sizeof(s) / sizeof(s[0]);

	for(i = 0; i < n; i++){
		printf("no: %d, name: %s, score: %d\n", p->no, p->name, (*p).score);
		p++;
	}

	return 0;
}
