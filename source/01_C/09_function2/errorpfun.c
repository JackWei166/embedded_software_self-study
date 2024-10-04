#include <stdio.h>
#include <string.h>

char *getstring();

int main(int argc, char *argv[]){
	char *r;

	r = getstring();
	printf("%s\n", r);
	
	(*r)++;
	printf("%s\n", r);

	return 0;
}

char *getstring(){
	char s[16];

	strcpy(s, "hello");

	return s;
}
