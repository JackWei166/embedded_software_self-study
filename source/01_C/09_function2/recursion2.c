#include <stdio.h>

int fib(int n);

int main(int argc, char *argv[]){
	int i;

	for(i = 1; i <= 10; i++){
		printf("%d ", fib(i));
	}
	puts("");

	return 0;
}

int fib(int n){
	if(n == 1 || n == 2){
		return 1;
	}

	return fib(n-1) + fib(n-2);
}
