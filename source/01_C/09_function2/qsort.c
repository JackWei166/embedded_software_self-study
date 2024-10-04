#include <stdio.h>
#include <stdlib.h>

int compare(const void *p, const void *q);

int main(int argc, char *argv[]){
	int n, i;
	int a[] = {2, 5, 6, 1, 7, 1};

	n = sizeof(a) / sizeof(a[0]);

	qsort(a, n, sizeof(int), compare);

	for(i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	puts("");

	return 0;
}

int compare(const void *p, const void *q){
	return *(int *)q - *(int *)p;
}
