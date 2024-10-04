#include <stdio.h>

int main(int argc, char *argv[])
{
	char arr[] = "welcome";
	int i, n;
	
	n = sizeof(arr) / sizeof(arr[0]);

	for(i = n - 2; i >= 0; i--){
		printf("%c", arr[i]);
	}
	puts("");

	return 0;
}
