#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

class Timer {
public:
	Timer()
	{
		hour = 0;
		min = 0;
		sec = 0;
	}

	~Timer()
	{
	}

	void addtimer(int sec=1)
	{
		this->min += (this->sec+sec) / 60;
		this->sec = (this->sec+sec) % 60;
	}

	void show()
	{
		printf("%2d:%2d:%2d\n", hour, min, sec);
	}

	Timer operator+(int sec)
	{
		Timer tem;
		tem.sec = this->sec+sec;
		return tem;
	}

	Timer operator+(Timer &x)
	{
		Timer tem;
		tem.sec = sec+x.sec;
		tem.min = min+x.min;
		tem.hour = hour+x.hour;
		return tem;
	}

	Timer operator++(int)
	{
		Timer tem = *this;
	
		sec++;

		return tem;
	}

	Timer operator++()
	{
		sec++;
		return *this;
	}

	bool operator==(Timer &x)
	{
		if (sec==x.sec && min==x.min && hour==x.hour) {
			return true;
		}

		return false;
	}

	int &operator[](int i)
	{
		static int err = -1;

		switch(i)
		{
		case 0: 
			return hour;
		case 1: 
			return min;
		case 2: 
			return sec;
		}

		return err;
	}

	operator int()
	{
		return sec+min*60+hour*60*60;
	}

	friend ostream &operator<<(ostream &out, const Timer &t);

private:
	int hour;
	int min;
	int sec;
};

ostream &operator<<(ostream &out, const Timer &t)
{
	out << "hour: "<<t.hour << " min: "<<t.min<<" sec: "<<t.sec<< endl;

	return out;
}

int main(void)
{
	Timer t;

	t.addtimer(3);

	int sec = t;
	
	cout<< sec <<endl;
}
