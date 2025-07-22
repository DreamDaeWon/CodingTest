#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> Str{};

	string Snum{};
	while (true)
	{
		cin >> Snum;
		

		if (Snum == "0")
		{
			break;
		}
		Str.push_back(Snum);
		
	}


	string rStr{};

	for (int i = 0; i < Str.size(); ++i)
	{
		rStr.clear();
		for (auto iter = Str[i].rbegin(); iter != Str[i].rend(); ++iter)
		{
			rStr.push_back(*iter);
		}

		if (Str[i] == rStr)
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
	
	return 0;
}