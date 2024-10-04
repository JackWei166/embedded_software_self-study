#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <exception>

using namespace std;

class argexception:public exception {
public:
	const char* what() const throw()
	{
		return "arg Err !";
	}
};

int myatoi(const char *str)
{
	if (*str < '0' || *str > '9') {
		throw argexception();
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
	catch(argexception e) {
		cout<< e.what() <<endl;
	}
	
	return 0;
}
