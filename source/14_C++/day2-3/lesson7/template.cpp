#include <stdio.h>
#include <iostream>

using namespace std;

template<typename XXX>
XXX add(XXX a, XXX b)
{
	return a+b;
}

template <>
bool add(bool a, bool b)
{
	if(a == true && b == true)
		return true;
	return false;
}

int main(void)
{
	cout<< add(1, 2) <<endl;
	cout<< add(1.1, 2.3) <<endl;
	cout<< add(true, false) <<endl;
	cout<< add(true, true) <<endl;
}
