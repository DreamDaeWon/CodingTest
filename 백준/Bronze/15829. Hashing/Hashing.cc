#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int AllSize{};

	cin >> AllSize;

	int Num{};

	int Input{};

	int Result{};

	char* Str = new char[AllSize+1];

	cin >> Str;

	for (int i = 0; i < AllSize; ++i)
	{
		Num = Str[i] - 96;
		Result += Num * pow(31, i);
	}

	Result = Result % 1234567891;


	cout << Result;


	delete[] Str;
	Str = nullptr;

	return 0;
}