#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s1[] = "how are you";
	char s2[] = "are";
	
	printf("%d\n", strstr(s1, s2) - s1);

	return 0;
}
