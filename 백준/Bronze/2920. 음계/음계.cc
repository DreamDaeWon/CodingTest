#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int AllNum[8]{};

	int ascending{};
	int descending{};
	
	for (int i = 0; i < 8; ++i)
	{
		cin >> AllNum[i];
		if (AllNum[i] == i + 1)
		{
			++ascending;
		}

		if (AllNum[i] == 8 - i)
		{
			++descending;
		}

	}

	if (ascending == 8)
	{
		cout << "ascending" << endl;
	}
	else if (descending == 8)
	{
		cout << "descending" << endl;
	}
	else
	{
		cout << "mixed" << endl;
	}


	return 0;
}