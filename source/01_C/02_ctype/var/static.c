#include <stdio.h>

int main(int argc, char *argv[])
{
	int i = 1;

	while(i < 5){
		//int a = 0;
		static int a = 0;

		a++;
		printf("%d\n", a);
		//puts("");

		printf("%d\n", i);
		i++;
	}

	return 0;
}
