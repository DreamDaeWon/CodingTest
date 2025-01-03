#include <iostream>

using namespace std;


int main()
{
	int AllNum[9]{};

	for (int i = 0; i < 9; ++i)
	{
		cin >> AllNum[i];
	}

	int Small{};
	int SmallIndex{};

	for (int i = 0; i < 9; ++i)
	{
		if (Small < AllNum[i])
		{
			SmallIndex = i+1;
			Small = AllNum[i];
		}
	}

	cout << Small << endl << SmallIndex << endl;

	return 0;
}
