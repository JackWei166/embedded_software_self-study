#include <stdio.h>
#include <string.h>

#define N 20

int main(int argc, char *argv[])
{
	//char arr[] = "welcome";
	char s[N] = {0};
	int i, j, n, ch;
	
	printf("Please input a string:");
	gets(s);

	n = strlen(s);
	i = 0;
	j = n - 1;

	while(i < j){
		ch = s[i];
		s[i] = s[j];
		s[j] = ch;
		i++;
		j--;
	}
	
	puts(s);

	return 0;
}
