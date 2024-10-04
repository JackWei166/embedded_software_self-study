#ifndef _ARR_
#define _ARR_

#include <iostream>

using namespace std;

template <typename XXX>
class ARR{
public:
	ARR():tail(0) {
	}

	void addtail(XXX data);
	void show(void);
	
private:
	XXX data[100];
	int tail;
};

template <typename XXX>
void ARR<XXX>::addtail(XXX data)
{
	this->data[tail++] = data;
}

template <typename XXX>
void ARR<XXX>::show(void)
{
	int i = 0;
	for (; i < tail; i++) {
		cout<< data[i] <<',';
	}
	cout<<endl;
}

#endif
