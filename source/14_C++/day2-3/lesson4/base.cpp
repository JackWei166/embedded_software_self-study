#include <iostream>

using namespace std;

class A {
public:
	A()
	{
	}

	virtual ~A()
	{ 
		cout<<"A~~~~~~~~~"<<endl; 
	}
	
	virtual void show()
	{
		cout<<"AAAAAAAAAAAAA"<<endl;
	}
};

class AX:public A {
public:
	~AX()
	{ 
		cout<<"AX~~~~~~~~~"<<endl; 
	}

	void show()
	{
		cout<<"BBBBBBBBBBBBB"<<endl;
	}
	
};

int main(void)
{
	A *p = new AX;
	delete p;

	return 0;
}
