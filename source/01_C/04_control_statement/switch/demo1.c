#include <stdio.h>

int main(int argc, char *argv[])
{
	enum weekday {
	sun, mon, tues, wed, 
	} a;

	a = wed;

	switch(a){
	
	case sun:
		printf("sun\n");
		break;
	
	case mon:
		printf("mon\n");
		break;
	
	case tues:
		printf("tues\n");
		break;
	
	case wed:
		printf("wed\n");
		break;
	
	default:
		printf("not in arange\n");
	
	}


	return 0;
}
