#include <stdio.h>

int main(int argc, char *argv[])
{
	int ch, dh;

	printf(">");
	ch = getchar();
	scanf(" %c", &dh);
		
	putchar(ch);
	putchar(dh);
	putchar('\n');
	printf("ch = %c\n", ch);

	return 0;
}
