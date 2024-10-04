#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int myatoi(const char *str)
{
	if (*str < '0' || *str > '9') {
		throw "wrong arg!!!!";
	} else {
		return atoi(str);
	}

	return 0;
}

int main(void)
{
	try {
		int data = myatoi("asdfas");

		cout<< data <<endl;
	}
	catch(const char *p) {
		cout<<p<<endl;
	}

	return 0;
}
