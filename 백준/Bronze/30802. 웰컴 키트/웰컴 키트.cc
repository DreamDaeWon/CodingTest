#include <iostream>
using namespace std;

int main()
{
	int AllNum{};
	int AllSize[6]{};
	int T{};
	int P{};

	cin >> AllNum;
	for (int i = 0; i < 6; ++i)
	{
		cin >> AllSize[i];
	}
	cin >> T >> P;


	int T_Shirt{};

	for (int i = 0; i < 6; ++i) 
	{
		T_Shirt += AllSize[i] / T;
		if (AllSize[i] % T > 0)
		{
			++T_Shirt;
		}

	}

	cout << T_Shirt << endl;


	cout << AllNum / P << " " << AllNum % P << endl;
}