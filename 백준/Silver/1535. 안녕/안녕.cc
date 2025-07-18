#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> dp{}; // dp

vector<int> downHp{}; // 감소하는 체력

vector<int> Joy{}; // 기쁨



int main()
{
	int N;

	cin >> N;

	dp.resize(N);

	downHp.resize(N);
	Joy.resize(N);

	for (int i = 0; i < N; ++i)
	{
		dp[i].resize(100,0);

		cin >> downHp[i];
	}

	for (int i = 0; i < N; ++i)
	{
		cin >> Joy[i];
	}

	for (int i = downHp[0]; i < 100; ++i)
	{
		dp[0][i] = Joy[0];
	}


	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < 100; ++j)
		{
			if (downHp[i] > j)
			{
				dp[i][j] = dp[i - 1][j];
				continue;
			}

			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - downHp[i]] + Joy[i]);

		}
	}

	cout << dp[N - 1][99];

	return 0;
}