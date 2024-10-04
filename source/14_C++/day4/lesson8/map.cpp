#include <iostream>
#include <map>

using namespace std;

int main(void)
{
	map<string, string> user_passwd;
	
	user_passwd.insert(user_passwd.begin(), pair<string, string>("aaa", "1111") );
	user_passwd.insert(user_passwd.begin(), pair<string, string>("aaa4", "114411") );
	user_passwd.insert(user_passwd.begin(), pair<string, string>("aaa2", "111331") );
	user_passwd.insert(user_passwd.begin(), pair<string, string>("aaa3", "111441") );

	map<string, string>::iterator i = user_passwd.begin();
	while(i != user_passwd.end())
	{
		cout<< (*i).first<< ',' <<(*i).second <<endl;
		i++;
	}

	cout<< user_passwd["aaa2"] << endl;

	return 0;
}
