#include <iostream>

using namespace std;

class A {
public:
	A(){
	}
	
	~A(){
	}

	void showx(void)
	{
		cout<<"xxxxxxxxxxxxxxx"<<endl;
	}
};

class AX:public A {
public:
	void showy(void)
	{
		cout<<"yyyyyyyyyyyyyyy"<<endl;
	}
};

int main(void)
{
	A a;
	a.showx();

	AX b;
	b.showx();
	b.showy();

	return 0;
}
