#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s1[] = "ab";
	char s2[] = "abc";
	
	printf("%d\n", strcmp(s1, s2));

	return 0;
}
