#include <iostream>

using namespace std;

class shape {
public:
	virtual double getC(void) = 0;
};

class Cir:public shape{
public:
	Cir(double ri):r(ri) 
	{ 
	}

	double getC(void)
	{
		return 2*3.14*r;	
	}

private:
	int r;
};

class Tri:public shape {
public:
	Tri(double a, double b, double c):e1(a),e2(b),e3(c)
	{ 
	}

	double getC(void)
	{
		return e1+e2+e3;	
	}

private:
	double e1;
	double e2;
	double e3;
};

class Rec: public shape
{
public:
	Rec(double e)
	{
		this->e = e;
	}
	
	double getC(void)
	{
		return 4*e;	
	}

private:
	double e;
};

double countC(shape *arr[], int n)
{
	double sum = 0;

	int i = 0;
	for (; i < n; i++) {
		sum += arr[i]->getC();
	}
	
	return sum;
}

int main(void)
{
	//shape x;

	Cir c(1);
	Rec r(3);
	Cir c1(2);
	Tri t(3,3,3);

	shape *arr[] = {&c, &r, &c1, &t};

	cout << "total C: "<<countC(arr, 4) << endl;

	return 0;
}
