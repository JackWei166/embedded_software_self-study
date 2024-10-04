#include <stdio.h>
#include <string.h>

#define N 50

int main(int argc, char *argv[]){
	char s1[N] = "welcome";
	char *s2 = "hello World!";

	strcpy(s1, s2);
	//strcpy(s2, s1);

	puts(s1);
	puts(s2);

	return 0;
}
