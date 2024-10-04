#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char *argv[])
{
	float a, b, c, q, area;
	
	printf("Please input a, b, c:");
	scanf("%f%f%f", &a, &b, &c);

	if(a + b <= c || a + c <= b || b + c <= a){
		printf("invalid input --1\n");
		return -1;
	}

	if(abs(a - b) >= a || abs(a - c) >= b || abs(b - c) >= a){	
		printf("invalid input --2\n");
		return -1;
	}

	q = (a + b + c) / 2;
	area = sqrt(q * (q - a) * (q - b) * (q - c));

	printf("%.2f %.2f %.2f %.2f\n", a, b, c, area);
	
	return 0;
}
