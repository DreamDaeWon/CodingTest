#include <iostream>
using namespace std;

int main()
{
	long long iA{};
	long long iB{};

	cin >> iA >> iB;

	long long iFinal = iA - iB;

	cout << abs(iFinal) << endl;

	return 0;
}