#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main(void)
{
#if 0
	vector<int> arr;

	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);
#endif
//	vector<double> arr;
	list<double> arr;
	arr.push_back(1.2);
	arr.push_back(1.2);
	arr.push_back(1.2);
	arr.push_back(1.2);
	arr.push_back(1.2);

//	vector<int>::iterator i = arr.begin();
//	vector<double>::iterator i = arr.begin();
	list<double>::iterator i = arr.begin();
	while (i != arr.end()) {
		cout<< *i <<endl;
		i++;
	}
	
	return 0;
}
