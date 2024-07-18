#include <iostream>

using namespace std;

int main()
{
	double iA{};
	double iB{};

	cin >> iA >> iB;

	
	if (iA > iB)
	{
		cout << ">" << endl;
	}
	else if (iA < iB)
	{
		cout << "<" << endl;
	}
	else if (iA == iB)
	{
		cout << "==" << endl;
	}

	return 0;
}