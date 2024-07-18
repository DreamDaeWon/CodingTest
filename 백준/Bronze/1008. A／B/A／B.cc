#include <iostream>

using namespace std;

int main()
{
	double iA{};
	double iB{};

	cin >> iA >> iB;

	cout.precision(10); // 소수점 몇 자리 수 까지 나타낼 것인지 적을 수 있는 함수
	cout << (double)(iA / iB) << endl;

	return 0;
}
