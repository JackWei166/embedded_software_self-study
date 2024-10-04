#include <stdio.h>

int main(int argc, char *argv[])
{
	char arr1[] = {'a', 'b', 'c'};
	char arr2[6] = {'d', 'e', 'f'};

	printf("arr1: %s %p\n", arr1, &arr1[2]);
	printf("arr2: %s %p\n", arr2, &arr2);

#if 0
	int i, n;
	n = sizeof(arr1) / sizeof(arr1[0]);
	for(i = 0; i < n; i++){
		printf("%c ", arr1[i]);
	}
	puts("");

	n = sizeof(arr2) / sizeof(arr2[0]);
	for(i = 0; i < n; i++){
		printf("%c ", arr2[i]);
	}
	puts("");
#endif

	return 0;
}
