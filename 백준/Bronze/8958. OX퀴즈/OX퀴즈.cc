#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int AllNum{};
	vector<string> AllStr{};

	cin >> AllNum;

	for (int i = 0; i < AllNum; ++i)
	{
		string Str{};
		cin >> Str;

		AllStr.push_back(Str);
	}

	int NowScore{};
	
	for (int i = 0; i < AllNum; ++i)
	{
		NowScore = 0;
		int UpScore{};
		for (int j = 0; j < AllStr[i].size(); ++j)
		{
			if (AllStr[i][j] == 'O')
			{
				++UpScore;
				NowScore += UpScore;
			}

			if (AllStr[i][j] == 'X')
			{
				UpScore = 0;
			}
		}
		cout << NowScore << endl;
	}
	

	return 0;
}