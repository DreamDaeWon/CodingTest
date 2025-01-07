#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str{};

	getline(cin, str);

	char cBefore{' '};

	int AllWord{};

	for (int i = 0; i < str.size(); ++i)
	{
		if (cBefore == ' ' && str[i] != ' ')
		{
			++AllWord;
		}

		cBefore = str[i];

	}

	cout << AllWord <<endl;

	return 0;
}