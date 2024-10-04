#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s1[] = "makeru";
	
	printf("%d\n", strlen(s1));
	printf("%d\n", sizeof(s1) / sizeof(s1[0]));

	return 0;
}
