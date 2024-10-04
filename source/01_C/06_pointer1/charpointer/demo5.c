#include <stdio.h>
#include <string.h>

#define N 100

int main(int argc, char *argv[]){
	char s1[N] = "welcome";
	char *s2 = "hello World!", *p;
	int i = 0;

	p = s2;

	while(*(s1 + i) != 0){
		i++;
	}

	while(*s2){
		*(s1 + i) = *s2;
		s2++;
		i++;
	}
	
	s2 = p;
	puts(s1);
	puts(s2);

	return 0;
}
