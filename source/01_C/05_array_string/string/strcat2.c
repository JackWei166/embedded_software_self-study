#include <stdio.h>
#include <string.h>

#define N 100

int main(int argc, char *argv[])
{
	char s1[] = "ab";
	char s2[N] = ".com.cn";
	
	strcat(s1, s2);

	printf("%p %p\n", s1, s2);
	puts(s1);
	puts(s2);

	return 0;
}
