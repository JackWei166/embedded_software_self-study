#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s1[] = "quit";
	char s2[] = "QUIT";
	
	printf("%d\n", strncmp(s1, s2, 4));
	printf("%d\n", strcasecmp(s1, s2));
	
	return 0;
}
