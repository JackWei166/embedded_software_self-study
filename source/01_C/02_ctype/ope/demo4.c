#include <stdio.h>

int main(int argc, char *argv[])
{
	int a = 8, b = 7, c = 0;

	//if((a - 1) < b && b++ && a++){
	if((a - 1) <= b && b++ && a++){
		printf("true:%d %d %d\n", a, b, c);
	}
	else{
		printf("false:%d %d %d\n", a, b, c);
	}

	return 0;
}
