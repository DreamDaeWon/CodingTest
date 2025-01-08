#include <iostream>

using namespace std;

int main()
{
	int AllNum[10]{};
	int ResultNum{};

	for (int i = 0; i < 10; ++i)
	{
		cin >> AllNum[i];
		AllNum[i] = AllNum[i] % 42;
	}

	for (int i = 0; i < 10; ++i)
	{
		int A{};
		for (int j = i; j < 10; ++j)
		{
			if (AllNum[i] == AllNum[j])
			{
				++A;
			}
		}
		if (A == 1)
		{
			++ResultNum;
		}
	}

	cout << ResultNum << endl;


	return 0;
}