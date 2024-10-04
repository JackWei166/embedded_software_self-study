#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char s[] = "abas$f$sf";
	int ch;

	ch = '$';

	printf("%d\n", strchr(s, ch) - s);
	printf("%d\n", strrchr(s, ch) - s);

	return 0;
}
