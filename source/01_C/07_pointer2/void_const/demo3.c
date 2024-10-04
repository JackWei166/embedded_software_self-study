#include <stdio.h>

int main(int argc, char *argv[]){
	int a[] = {1, 2, 3, 4, 5, 6};
	int i, n;
	void *q;
	int *p;
	
	q = (void *)a;
	p = (int *)q;

	n = sizeof(a) / sizeof(a[0]);
	for(i = 0; i < n; i++){
		printf("%d ", *(p + i));
		//p++;
	}
	puts("");

	return 0;
}

