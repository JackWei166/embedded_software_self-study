#ifndef _ARR_
#define _ARR_

class ARR {
public:
	ARR():tail(0) {
	}

	void addtail(int data);
	void show(void);

//private:
	int data[100];
	int tail;
};

#endif
