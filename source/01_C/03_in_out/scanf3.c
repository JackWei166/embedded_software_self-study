#include <stdio.h>

int main(int argc, char *argv[])
{
	char yy, mm, dd;

	printf(">");
	//scanf("%d%d%d", &yy, &mm, &dd);
	scanf("%c%c%c", &yy, &mm, &dd);
	
	printf("%d:%02d:%02d\n", yy, mm, dd);

	return 0;
}
