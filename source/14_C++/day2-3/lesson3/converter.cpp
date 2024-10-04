#include <iostream>

using namespace std;

class Converter {
public:
	Converter(double rate)
	{
		this->rate = rate;
	}

	double operator()(double rmb)
	{
		return rmb*rate;
	}
private:
	double rate;
};


/*
double RMBto(double rmb, double rate)
{
	return rmb*rate;
}
*/

int main(void)
{
	Converter RMBtoUS(6.4);
	cout << RMBtoUS(10) << endl;
	cout << RMBtoUS(10) << endl;
	
	Converter RMBtoE(8.4);
	cout << RMBtoE(100) << endl;
	cout << RMBtoE(100) << endl;
}
