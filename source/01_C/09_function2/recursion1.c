#include <stdio.h>

int fac(int n);

int main(int argc, char *argv[]){
	int n, ret;

	printf("Please input:");
	scanf("%d", &n);
	
	ret = fac(n);

	printf("%d\n", ret);

	return 0;
}

int fac(int n){
	int ret;

	if(n == 0 || n == 1){
		return 1;
	}

	ret = n * fac(n-1);

	return ret;
}
