#include <iostream>
#include <string>
using namespace std;

int main()
{
	int iA{0};
	int iB{0};

	while (true)
	{
		cin >> iA >> iB;

		if (iA == 0 && iB == 0)
		{
			break;
		}

		if (iA > iB)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}