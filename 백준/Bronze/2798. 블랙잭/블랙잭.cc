#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int iAllCardNum{};

	int WantNum{};

	vector<int> AllNum{};

	cin >> iAllCardNum >> WantNum;

	int A{};
	for (int i = 0; i < iAllCardNum; ++i)
	{
		cin >> A;
		AllNum.push_back(A);
	}

	int iResult{};
	int Last{2100000000};
	int Now{};

	for (int i = 0; i < AllNum.size(); ++i)
	{
		for (int j = 0; j < AllNum.size(); ++j)
		{
			if (j == i)
			{
				continue;
			}
			for (int k = 0; k < AllNum.size(); ++k)
			{
				if (j == k || i == k)
				{
					continue;
				}
				Now = AllNum[i] + AllNum[j] + AllNum[k];

				Now = WantNum - Now;

				if (0 <= Now && Last > Now)
				{
					Last = Now;
					iResult = AllNum[i] + AllNum[j] + AllNum[k];
				}
			}
		}
	}

	cout << iResult;

	return 0;
}