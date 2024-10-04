#include "arr.h"

int main()
{
	ARR arr;
	init(&arr);

	int n = 10;
	while (n--) {
		addtail(&arr, n);
	}

	show(&arr);


	ARR arr1;
	init(&arr1);

	int i = 0;
	for (;i < 10; i++) {
		addtail(&arr1, i);
	}

	show(&arr1);

	return 0;
}
