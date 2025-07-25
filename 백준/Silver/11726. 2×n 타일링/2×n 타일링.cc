#include <iostream>
#include<vector>

using namespace std;

int n;



int main()
{
	cin >> n;

	vector<size_t> Vec(n+1,1);

	if (n == 1)
	{
		cout << 1 << endl;
		return 0;
	}

	for (int i = 2; i <= n; ++i)
	{
		Vec[i] = Vec[i - 1] + Vec[i - 2];
		Vec[i] %= 10007;
	}

	cout << Vec[n];

}