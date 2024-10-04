#include <stdio.h>
#include <math.h>

#define _DEBUG_

int main(int argc, char *argv[]){
	int m = 625;

#ifdef _DEBUG_
	printf("%s %s, %d\n", __FILE__, __FUNCTION__,__LINE__);
#endif

	m = sqrt(m);

	printf("%d\n", m);

	return 0;
}
