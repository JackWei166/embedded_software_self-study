#include <stdio.h>

int array_sum(int a[], int n);

int main(int argc, char *argv[]){
	int a[] = {1, 2, 3, 4, 5};
	int sum;

	sum = array_sum(a, sizeof(a)/sizeof(a[0]));

	printf("%d\n", sum);

	return 0;
}

int array_sum(int a[], int n){
	int sum = 0, i;

	for(i = 0; i < n; i++){
		sum += a[i];
	}
	
	return sum;
}
