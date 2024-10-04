#include <stdio.h>

void del_space(char *s);

int main(int argc, char *argv[]){
	char s[] = "a  b  c";

	puts(s);

	del_space(s);
	puts(s);

	return 0;
}

void del_space(char *s){
	char *p;

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
}
