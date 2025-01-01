#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<int> vecA{};
	vector<int> vecB{};

	
	int A{};
	int B{};

	while (!(cin >> A >> B).eof())
	{
		vecA.push_back(A);
		vecB.push_back(B);
	}


	for (int i = 0; i < vecA.size(); ++i)
	{
		cout << vecA[i] + vecB[i] << endl;
	}

	return 0;
}