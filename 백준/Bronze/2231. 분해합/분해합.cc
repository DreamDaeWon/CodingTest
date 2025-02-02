#include<iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	size_t Num{}; // 숫자

	size_t Digit{}; // 자리수

	size_t All_Digit_Plus{}; // 모든 자리수의 합

	size_t Result{ 0 }; // 결과



	cin >> Num; // 자리 수 입력 받기




	for (size_t i = 1; i < Num; ++i)
	{
		All_Digit_Plus = 0;

		string strNum{};
		strNum = to_string(i);

		Digit = strNum.size() - 1;

		size_t NowDigit{ 0 };
		size_t NowNum{ i };
		for (size_t j = Digit; j >= 1; --j)
		{
			NowDigit = (size_t)pow(10,j);
			All_Digit_Plus += NowNum / NowDigit;
			NowNum -= (NowNum / NowDigit) * NowDigit;
		}
		All_Digit_Plus += NowNum;

		if (All_Digit_Plus + i == Num)
		{
			Result = i;
			break;
		}
	}



	cout << Result;

	return 0;
}