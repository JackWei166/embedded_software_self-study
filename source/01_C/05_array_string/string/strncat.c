#include <stdio.h>
#include <string.h>

#define N 100

int main(int argc, char *argv[])
{
	char s1[N] = "www.makeru";
	char s2[] = ".com.cn";
	
	strncat(s1, s2, 4);

	puts(s1);
	puts(s2);

	return 0;
}