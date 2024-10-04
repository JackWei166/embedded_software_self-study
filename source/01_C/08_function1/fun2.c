#include <stdio.h>

double x = 2;
int n = 3;

double power();

int main(int argc, char *argv[]){
	
	//double x = 2, ret;
	//int n = 3;
	double ret;

	ret = power();

	printf("%.2lf %d = %.2lf\n", x, n, ret);

	return 0;
}

double power(){
	double ret = 1;
	int i;

	for(i = 0; i < n; i++){
		ret *= x;
	}

	return ret;
}
