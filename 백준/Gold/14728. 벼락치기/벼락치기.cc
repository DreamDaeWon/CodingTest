#include <iostream>
#include <vector>

using namespace std;

int main()
{
	// 전체 배열, 각 물건의 무게, 가치 생성
	vector<vector<int>> dp{};
	vector<int>All_W{};
	vector<int>All_V{};

	// 입력받기
	int N, K;
	cin >> N >> K;

	// 입력받은만큼 크기 늘리기
	dp.resize(N);

	int W, V;

	for (int i = 0; i < N; ++i)
	{
		// 크기 바꾸고 채우기
		dp[i].resize(K + 1);
		fill(dp[i].begin(), dp[i].end(), 0);

		// 각 물건 입력받기
		cin >> W >> V;
		All_W.push_back(W);
		All_V.push_back(V);
	}

	
	// 표 첫줄 채우기
	for (int i = 1; i < K + 1; ++i)
	{
		if (All_W[0] > i)
			dp[0][i] = 0;
		else
			dp[0][i] = All_V[0];
	}

	// 표 채우기
	for (int i = 1; i < N; ++i) // 물건
	{
		for (int j = 1; j < K + 1; ++j) // 무게
		{
			if (All_W[i] > j)
			{
				dp[i][j] = dp[i-1][j];
			}
			else
			{
				dp[i][j] = max(dp[i-1][j], dp[i - 1][j-All_W[i]] + All_V[i]);
			}
		}
	}

	cout << dp[N-1][K];

	return 0;
}