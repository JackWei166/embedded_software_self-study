#include <stdio.h>

int main(int argc, char *argv[])
{
	int a[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, i, j, n;
	int t;

	n = sizeof(a) / sizeof(a[0]);

	for(i = 0; i < n - 1; i++){
		for(j = 0; j < n - 1 - i; j++){
			if(a[j] > a[j+1]){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}

	for(i = 0; i < n; i++){
			printf("%d ", a[i]);
	}
	puts("");

	return 0;
}
