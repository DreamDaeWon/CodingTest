#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int A{}, B{};

	vector<int> vecA{}, vecB{};

	while (true)
	{
		cin >> A >> B;

		if (A == 0 && B == 0)
		{
			break;
		}

		vecA.push_back(A);
		vecB.push_back(B);
	}


	for (int i = 0; i < vecA.size(); ++i)
	{
		cout << vecA[i] + vecB[i] << endl;
	}

	return 0;
}