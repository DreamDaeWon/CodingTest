#include <iostream>

using namespace std;

int main()
{
	double iA{};
	double iB{};

	cin >> iA >> iB;

	cout.precision(10);
	cout << (double)(iA / iB) << endl;

	return 0;
}