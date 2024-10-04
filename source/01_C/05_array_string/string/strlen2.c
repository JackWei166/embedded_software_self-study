#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s1[] = "\tab\nc\vd\\e";
	char s2[] = "\x69\141";
	
	printf("%d\n", strlen(s1));
	printf("%d\n", sizeof(s1) / sizeof(s1[0]));

	printf("%d\n", strlen(s2));
	printf("%d\n", sizeof(s2) / sizeof(s2[0]));
	puts(s2);

	return 0;
}
