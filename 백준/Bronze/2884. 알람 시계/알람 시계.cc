#include <iostream>

using namespace std;


int main()
{
	int H{};
	int M{};

	cin >> H >> M;

	if (M < 45)
	{
		if (H == 0)
		{
			cout << 23 << " " << 60 - (45 - M) << endl;
		}
		else
		{
			cout << H - 1 << " " << 60 - (45 - M) << endl;
		}
	}
	else if (M >= 45)
	{
		cout << H<< " " << M - 45 << endl;
	}
	return 0;
}