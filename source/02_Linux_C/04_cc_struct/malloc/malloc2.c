#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char *p;
	char s[] = "wel";

	p = s;

	strcpy(p, "welcome");

	printf("%s\n", p);

	return 0;
}
