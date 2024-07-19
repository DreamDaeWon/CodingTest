#include <iostream>
using namespace std;

int main()
{
	int iStar{};
	cin >> iStar;

	for (int i = 0; i < iStar; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}


	return 0;
}