#include <iostream>
#include <string>
using namespace std;

int main()
{
	int iChess[6]{ 1,1,2,2,2,8 };
	int iInfo{};

	for (int i = 0; i < 6; ++i)
	{
		cin >> iInfo;

		iChess[i] = iChess[i] - iInfo;

		cout << iChess[i] << endl;
	}
	return 0;
}