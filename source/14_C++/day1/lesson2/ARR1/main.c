#include "arr.h"

int main(void)
{
	ARR arr;
	
	init(&arr);

	int n = 10;
	while (n--) {
		arr.addtail(&arr, n);
	}

	arr.show(&arr);

//	arr.tail = 0;
	
//	arr.show(&arr);
	
	return 0;
}
