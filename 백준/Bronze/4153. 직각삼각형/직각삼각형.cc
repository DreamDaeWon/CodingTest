#include <iostream>
#include <vector>

using namespace std;

int main()
{

	struct Num
	{
		int Nums[3]{};
	};

	vector<Num> AllNum{};

	Num InNums{};

	while (true)
	{
		cin >> InNums.Nums[0] >> InNums.Nums[1] >> InNums.Nums[2];

		if (InNums.Nums[0] == 0 && InNums.Nums[1] == 0 && InNums.Nums[2] == 0)
		{
			break;
		}

		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				if (InNums.Nums[j] > InNums.Nums[j + 1])
				{
					int Change = InNums.Nums[j];
					InNums.Nums[j] = InNums.Nums[j + 1];
					InNums.Nums[j + 1] = Change;
				}
			}
		}

		AllNum.push_back(InNums);
	}


	for (int i = 0; i < AllNum.size(); ++i)
	{
		if (((AllNum[i].Nums[0] * AllNum[i].Nums[0]) + (AllNum[i].Nums[1] * AllNum[i].Nums[1])) == (AllNum[i].Nums[2] * AllNum[i].Nums[2]))
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}


	return 0;
}