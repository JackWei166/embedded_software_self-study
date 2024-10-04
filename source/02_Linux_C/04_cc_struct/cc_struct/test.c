#include <stdio.h>
#include <math.h>

#define _DEBUG_

int main(int argc, char *argv[]){
	double m = 625, n;
		
	n = sqrt(m);

#ifdef _DEBUG_
	printf("debug:%.2lf\n", n);
#else
	printf("release:%.2lf\n", n);
#endif

	return 0;
}
