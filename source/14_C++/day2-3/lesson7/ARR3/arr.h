#ifndef _ARR_
#define _ARR_

#include <iostream>

using namespace std;

template <typename XXX, int SIZE>
class ARR {
public:
	ARR():tail(0) {
	}

	void addtail(XXX data);
	void show(void);
	
private:
	XXX data[SIZE];
	int tail;
};

template <typename XXX, int SIZE>
void ARR<XXX, SIZE>::addtail(XXX data)
{
	this->data[tail++] = data;
}

template <typename XXX, int SIZE>
void ARR<XXX, SIZE>::show(void)
{
	int i = 0;
	for (; i < tail; i++) {
		cout<< data[i] <<',';
	}
	cout<<endl;
}

#endif
