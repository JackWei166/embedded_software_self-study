#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int no;
	char name[32];
	int score;
} Stu;

Stu *get_info(){
	Stu *s;

	if((s = (Stu *)malloc(sizeof(Stu))) == NULL){
		printf("Malloc failed!");
		return NULL;
	}

	s->no = 1;
	strcpy(s->name, "s1");
	s->score = 88;
	
	return s;
}

int main(int argc, char *argv[]){
	Stu *s;

	if((s = get_info()) == NULL){
		printf("Getting info failed!");
		return -1;
	}

	printf("%d %s %d\n", s->no, s->name, s->score);

	free(s);
	s = NULL;

	return 0;
}
