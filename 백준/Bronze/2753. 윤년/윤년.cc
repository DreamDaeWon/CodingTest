#include <iostream>
#include <string>
using namespace std;

int main()
{
	int iYear{}; // 입력받는 연도

	cin >> iYear;

	if (((iYear % 4 == 0) && (iYear % 100 != 0)) || (iYear % 400 == 0)) // 윤년이면?
	{
		cout << 1 << endl;
	}
	else
	{
		cout << 0 << endl;
	}

	return 0;
}