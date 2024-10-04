#include <stdio.h>
#include <string.h>

#define N 32

struct stu {
	int no;
	char name[N];
	int score;
} s3 = {3, "s3"}, s4 = {4, "s4", 91};

int main(int argc, char *argv[]){
	struct stu s1, s2;

	strcpy(s1.name, "s1");
	s1.score = 88;
	printf("no: %d, name: %s, score: %d\n", s1.no, s1.name, s1.score);

	s2 = s1;
	s2.no = 2;
	s2.name[0] = 'S';
	printf("no: %d, name: %s, score: %d\n", s2.no, s2.name, s2.score);
	printf("no: %d, name: %s, score: %d\n", s3.no, s3.name, s3.score);
	printf("no: %d, name: %s, score: %d\n", s4.no, s4.name, s4.score);


	return 0;
}
