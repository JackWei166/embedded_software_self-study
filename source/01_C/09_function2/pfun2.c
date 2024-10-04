#include <stdio.h>
#include <string.h>

#define N 50

char *del_space(char *s);

int main(int argc, char *argv[]){
	char s[] = "a  b  c";
	char s1[N], s2[N];

	puts(s);

	strcpy(s1, strcpy(s2, del_space(s)));
	puts(s);
	puts(s1);
	puts(s2);

	return 0;
}

char *del_space(char *s){
	char *p, *r;

	r = s;
	p = s;

	while(*s){
		if(*s == ' '){
			s++;
		}
		else{
			*p = *s;
			p++;
			s++;
		}
	}	
	*p = '\0';

	return r;
}
