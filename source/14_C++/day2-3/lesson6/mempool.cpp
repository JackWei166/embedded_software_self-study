#include <iostream>

using namespace std;

class mempool {
public:
	explicit mempool(int size) {
		data = new char[size];	
		cout<< "cccccccccc" <<endl;
	}

	~mempool()
	{
		delete [] data;
	}

private:
	char *data;
};

int main()
{
//	mempool a(100);
	mempool a = 100;
}
