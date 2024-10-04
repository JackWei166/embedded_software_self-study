#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[]){
	char s1[] = "hello World!";
	char s2[] = "hello World!";
	char *p;

	p = s1;
	while(*p){
		if(isalpha(*p)){
			if(isupper(*p)){
				*p = tolower(*p);
			}
			else{
				*p = toupper(*p);
			}
		}

		p++;
	}
	printf("%s\n", s1);

	p = s2;
	printf("%s\n", p);

	return 0;
}
