#include<iostream>
#include <string>

using namespace std;

int main()
{
	int T{}; // 자리수

	string All{}; // 모든 숫자

	int Sum{};

	cin >> T;


	cin >> All;


	for (int i = 0; i < T; ++i)
	{
		Sum += All[i]-48;
	}

	cout << Sum << endl;
	return 0;
}