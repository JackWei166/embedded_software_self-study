#include <stdio.h>

void swap(int a, int b);

int main(int argc, char *argv[]){
	
	int a = 1, b = 2;

	printf("%d %d\n", a, b);
	
	swap(a, b);

	printf("%d %d\n", a, b);

	return 0;
}

void swap(int a, int b){
	int t;
	
	t = a;
	a = b;
	b = t;
}
