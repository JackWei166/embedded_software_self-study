#include <stdio.h>

int main(int argc, char *argv[])
{
	int a;
	char x;

	printf(">");
	scanf("%d", &a);
	scanf("%*c%c", &x);
	
	printf("%d %c %d\n", a, x, x);

	return 0;
}
