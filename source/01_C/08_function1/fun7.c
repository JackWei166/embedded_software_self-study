#include <stdio.h>

int str_fun(char *s);

int main(int argc, char *argv[]){
	char s[] = "Welcome to Beijing!";
	int n;

	n = str_fun(s);

	printf("%d\n", n);
	printf("%s\n", s);

	return 0;
}

int str_fun(char *s){
	int num = 0;

	while(*s){
		if(*s > 'a' && *s < 'z'){
			num++;
			*s -= ' ';
		}
		s++;
	}
	
	return num;
}
