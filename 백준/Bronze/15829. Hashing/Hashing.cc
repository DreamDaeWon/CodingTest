#include <iostream>
#include <string>
#include <cmath>
using namespace std;


size_t my_pow(size_t num1, size_t num2)
{
	size_t Fin{1};
	for (size_t i = 0; i < num2; ++i)
	{
		Fin *= num1;

		if (Fin >= 1234567891)
		{
			Fin %= 1234567891;
		}
	}

	return Fin;
}



int main()
{
	size_t Size{};
	
	cin >> Size;

	string Str{};

	cin >> Str;


	size_t iC{};

	size_t Fin{}; // 결과

	for (size_t i = 0 ; i < Size; ++i)
	{
		iC = (char)Str[i] - 'a' + 1;
		
		Fin += iC * my_pow(31, i);

		if (Fin >= 1234567891)
		{
			Fin %= 1234567891;
		}

	}

	cout << Fin;

	return 0;
}