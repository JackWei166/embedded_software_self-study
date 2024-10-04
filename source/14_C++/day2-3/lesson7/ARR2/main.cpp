#include "arr.h"

int main()
{
	ARR<int> arr;

	arr.addtail(1);
	arr.addtail(2);
	arr.addtail(3);
	arr.addtail(4);

	arr.show();

	ARR<double> arr1;

	arr1.addtail(1.1);
	arr1.addtail(22.3);
	arr1.addtail(3.5);
	arr1.addtail(4.9);

	arr1.show();

	return 0;
}
