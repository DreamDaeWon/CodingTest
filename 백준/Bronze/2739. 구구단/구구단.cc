#include <iostream>
using namespace std;

int main()
{
	int iNum{};

	cin >> iNum;

	for (int i = 1; i <= 9; ++i)
	{
		cout << iNum << " * " << i << " = " << iNum * i << endl;
	}

	return 0;
}