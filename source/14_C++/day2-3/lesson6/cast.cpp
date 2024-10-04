#include <stdio.h>
#include <iostream>
#include <typeinfo>

using namespace std;

class A {
public:
	virtual void show()
	{
		cout<<"aaaaaaa"<<endl;
	}
};

class B:public A {
public:
	void show()
	{
		cout<<"bbbbbbbb"<<endl;
	}

};

int main(void)
{
	try {

		A a;	
		B &p = dynamic_cast<B &>( a );
	}
	catch(bad_cast e)
	{
		cout<<e.what()<<endl;
	}

	return 0;
}
