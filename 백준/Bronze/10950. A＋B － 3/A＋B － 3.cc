#include <iostream>
#include <vector>


using namespace std;

int T{};

int main()
{
	cin >> T;

	vector<int> vecA{};
	vector<int> vecB{};

	for (int i = 0; i < T; ++i)
	{
		int A{}, B{};
		cin >> A>> B;
		
		vecA.push_back(A);
		vecB.push_back(B);

	}


	for (int i = 0; i < T; ++i)
	{
		cout << vecA[i] + vecB[i] << endl;
	}


	return 0;
}