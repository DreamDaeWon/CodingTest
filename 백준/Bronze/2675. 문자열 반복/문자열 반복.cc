#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

	int AllNum{};
	cin >> AllNum;

	vector<string> AllStr{};
	vector<int> StrNum{};

	for (int i = 0; i < AllNum; ++i)
	{
		string Str{};
		int Num{};

		cin >> Num;
		cin >> Str;
	

		AllStr.push_back(Str);
		StrNum.push_back(Num);

	}

	for (int i = 0; i < AllNum; ++i)
	{
		for (int j = 0; j < AllStr[i].size(); ++j)
		{
			for (int k = 0; k < StrNum[i]; ++k)
			{
				cout << AllStr[i][j];
			}
		}
		cout << endl;
	}



	return 0;
}