#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a>b;
}

void show(int data)
{
	cout<< data<< endl;
}

bool fcmp(int data)
{
	return data == 34;
}

int main()
{
	int arr[] = {1,1234,23,4,23,42,34,23,42,34,2,2,2,444,22};
	int n = sizeof(arr)/sizeof(int);

	int *p = find_if(arr, arr+n, fcmp);
	if (p != arr+n) {
		cout<<"got it !\n";
	}

	cout <<"num of 34: "<< count_if(arr, arr+n, fcmp) << endl;

	for_each(arr, arr+n, show);

	sort(arr, arr+n);
	cout<<"xxxxxxxxxxxxxxxxxxx\n";
	unique(arr, arr+n);

	for_each(arr, arr+n, show);
}

