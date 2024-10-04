#include <stdio.h>

int main(int argc, char *argv[]){
	int a[] = {1, 2, 3, 4, 5, 6};
	int i, n;
	void *p;
	
	p = (void *)a;
		
	n = sizeof(a) / sizeof(a[0]);
	for(i = 0; i < n; i++){
		printf("%d ", *((int *)p + i));
		//p++;
	}
	puts("");

	return 0;
}

