#include <stdio.h>

int main(int argc, char *argv[]){
	int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
	int *p[2], i, j, sum = 0;

	p[0] = a[0];
	p[1] = a[1];
	
	printf("%d\n", sizeof(p));
	
	for(i = 0; i < 2; i++){
		for(j = 0;j < 3; j++){
			sum += *(p[i] + j);
		}
	}

	printf("%d\n", sum);
	
	return 0;
}
