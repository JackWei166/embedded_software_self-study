#include "arr.h"
#include <iostream>

using namespace std;

class ARRX:public ARR {
public:
	int ever(void)
	{
		int i = 0;
		int sum = 0;

		for (;i < tail; i++) {
			sum += data[i]; 
		}

		return sum/tail;
	}
};

class Stuma {
public:
	Stuma() {
	}

	~Stuma() {
	}
	
	void savescore(int score)
	{
		scorearr.addtail(score);
	}
	
	int everscore(void)
	{
		return scorearr.ever();
	}

	void showscore(void)
	{
		scorearr.show();
	}

private:
	//ARR scorearr;
	ARRX scorearr;
};

int main(void)
{
	Stuma mmm;

	mmm.savescore(23);
	mmm.savescore(44);
	mmm.savescore(55);
	mmm.savescore(23);

	mmm.showscore();

	cout << mmm.everscore() <<endl;

	return 0;
}
