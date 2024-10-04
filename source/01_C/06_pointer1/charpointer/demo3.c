#include <stdio.h>

int main(int argc, char *argv[]){
	char *s1 = "hello World!";
	char *s2 = "hello World!";

	//*s1 -= 32;

	printf("%p %p %s\n", &s1, s1, s1);
	printf("%p %p %s\n", &s2, s2, s2);

	return 0;
}
