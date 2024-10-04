#include <stdio.h>

int main(int argc, char *argv[])
{
	int yy, mm, dd;

	printf(">");
	//scanf("%d%d%d", &yy, &mm, &dd);
	scanf("%4d%2d%2d", &yy, &mm, &dd);
	
	printf("%d:%02d:%02d\n", yy, mm, dd);

	return 0;
}
