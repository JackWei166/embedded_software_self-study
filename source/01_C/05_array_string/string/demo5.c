#include <stdio.h>
#include <string.h>

#define N 20

int main(int argc, char *argv[])
{
	//char arr[] = "welcome";
	char s[N] = {0};
	int i, n;
	
	printf("Please input a string:");
	gets(s);

	n = strlen(s);

	for(i = n - 1; i >= 0; i--){
		printf("%c", s[i]);
	}
	puts("");

	return 0;
}
