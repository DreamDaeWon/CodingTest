#include <iostream>
#include <string>
using namespace std;

int main()
{
	int iStar{};

	cin >> iStar;

	for (int i = iStar; i > 0; --i)
	{
		for (int j = 0; j < i-1; ++j)
		{
			cout << " ";
		}
		for (int j = 0; j < (iStar+1) - i; ++j)
		{
			cout << "*";
		}
		cout << endl;
	}


	return 0;
}