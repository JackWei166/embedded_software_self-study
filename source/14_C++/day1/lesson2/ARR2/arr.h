#ifndef _ARR_
#define _ARR_

class ARR {
public:
	ARR():tail(0) {
	}

	void addtail(int data);
	void show(void);
	
	friend void rev(ARR &arr);
	
private:
	int data[100];
	int tail;
};

#endif
