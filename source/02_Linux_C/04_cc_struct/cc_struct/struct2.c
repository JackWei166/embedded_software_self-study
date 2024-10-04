#include <stdio.h>
#include <string.h>

#define N 32

struct stu {
	int no;
	char name[N];
	struct {
		int year;
		int month;
		int day;
	} birth;
	int score;
} s1 = {1, "s1", {1992, 9, 9}, 90};

int main(int argc, char *argv[]){
	struct stu s2;
	
	s2.no = 2;
	strcpy(s2.name, "s2");
	s2.birth.year = 1993;
	s2.birth.month = 10;
	s2.birth.day = 10;
	s2.score = 89;

	printf("%d %s %d-%02d-%02d %d\n", s1.no, s1.name, s1.birth.year, s1.birth.month, s1.birth.day, s1.score);
	printf("%d %s %d-%02d-%02d %d\n", s2.no, s2.name, s2.birth.year, s2.birth.month, s2.birth.day, s2.score);
	
	return 0;
}
