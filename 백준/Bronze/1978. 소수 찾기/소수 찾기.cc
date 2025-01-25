#include <iostream>
//#include <vcruntime_string.h>
using namespace std;

int main()
{
	int AllNum[1000]{};
	int PrimeNum{};
	int N{};
	//memset(AllNum, -1, sizeof(AllNum));

	AllNum[0] = 1;

	for (int i = 2; i <= 1000; ++i)
	{
		if (AllNum[i - 1] == 0)
		{
			for (int j = i + i; j<=1000; j += i)
			{
				AllNum[j - 1] = 1;
			}
		}
		
	}

	cin >> N;

	int A{};

	for (int i = 0; i < N; ++i)
	{
		cin >> A;

		if (AllNum[A-1] == 0) // 1소수아님
		{
			++PrimeNum;
		}
	}

	cout << PrimeNum << endl;

	return 0;
}