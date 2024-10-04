#include <stdio.h>

int main(int argc, char *argv[])
{
	int i;
	int a[] = {1, 2, 3, 4, 5, 6};

	for(i = 0; i < sizeof(a) / sizeof(a[0]); i++){
			printf("%p %d\n", &a[i], a[i]);
	}

	return 0;
}
