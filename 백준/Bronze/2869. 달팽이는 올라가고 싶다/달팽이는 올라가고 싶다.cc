#include <iostream>

using namespace std;

int main()
{
	int A, B, V;

	cin >> A >> B >> V;

	int Count{};

	int Num{};

	while (true)
	{
		Num = V/A;
		if (0 >= Num || (Num == 1 && V % A == 0))
		{
			++Count;

			cout << Count << endl;
			break;
		}

		Count += Num;

		V = V - (A * Num) + (B * Num);

	}

	return 0;
}