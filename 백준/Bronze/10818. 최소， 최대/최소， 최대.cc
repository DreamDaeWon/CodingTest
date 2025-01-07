#include <iostream>
#include <vector>
using namespace std;


int main()
{
	int Num{};
	vector<int>AllNum{};

	cin >> Num;

	for (int i = 0; i < Num; ++i)
	{
		int A{};
		cin >> A;

		AllNum.push_back(A);
	}

	int Small{ 2000000 };
	int Big{ -2000000 };

	for (int i = 0; i < Num; ++i)
	{
		if (Small > AllNum[i])
		{
			Small = AllNum[i];
		}

		if (Big < AllNum[i])
		{
			Big = AllNum[i];
		}
	}

	cout << Small << " " << Big << endl;

	return 0;
}