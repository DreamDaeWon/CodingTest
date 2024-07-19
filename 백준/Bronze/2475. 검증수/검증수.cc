#include <iostream>
using namespace std;

int main()
{
	int iNumber[5]{};
	for (int i = 0; i < 5; ++i)
	{
		cin >> iNumber[i];
	}

	int iAllNum{};

	for (int i = 0; i < 5; ++i)
	{
		iAllNum += iNumber[i] * iNumber[i];
	}


	cout << iAllNum % 10 << endl;

	return 0;
}