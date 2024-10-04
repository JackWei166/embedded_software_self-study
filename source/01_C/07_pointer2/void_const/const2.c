#include <stdio.h>

int main(int argc, char *argv[]){
	int m = 10;
	const int *p = &m;
	int * const q = &m;
	const int * const r = &m;

	p++;

	(*q)++;

	r++;
	(*r)++;

	return 0;
}

