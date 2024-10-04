#include <stdio.h>

double power(double x, int n);

int main(int argc, char *argv[]){
	
	double x = 2, ret;
	int n = 3;

	ret = power(x, n);

	printf("%.2lf\n", ret);

	printf("%p %p\n", &x, &n);

	return 0;
}

double power(double x, int n){
	double ret = 1;
	int i;

	for(i = 0; i < n; i++){
		ret *= x;
	}

	printf("%p %p\n", &x, &n);

	return ret;
}
