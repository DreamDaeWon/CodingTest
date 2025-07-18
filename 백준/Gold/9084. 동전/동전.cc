#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> dp{};

vector<int> Fin{}; // 답안


void Solve(int N, vector<int>& Coins, int M)
{
	// dp 만들기
	dp.resize(N);

	for (int i = 0; i < N; ++i)
	{
		dp[i].resize(M + 1, 0);
	}

	// 0번째 1로 채우기
	for (int i = 0; i < N; ++i)
	{
		dp[i][0] = 1;
	}

	// 맨 윗 줄 구하기
	for (int i = 0; i < M + 1; ++i)
	{
		dp[0][i] = (int)(i % Coins[0] == 0);
	}


	// dp 채우기
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < M + 1; ++j)
		{
			if (Coins[i] > j) // 만약 아직 동전보다 돈이 작을경우
			{
				dp[i][j] = dp[i - 1][j]; // 위에꺼가 최고답이니까 그대로
				continue;
			}
			
			dp[i][j] = dp[i][j - Coins[i]] + dp[i - 1][j];

		}
	}


	// 답 구한것 넣기
	Fin.push_back(dp[N-1][M]);

	
	// dp 비우기
	for (int i = 0; i < N; ++i)
	{
		dp[i].clear();
	}
	dp.clear();

}



int main()
{
	int T; // 테스트의 개수

	int N; // 동전의 가지 수

	vector<int> Coins{}; // 동전 금액

	int M; // 금액

	
	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		cin >> N;
		Coins.clear();
		Coins.resize(N);
		for (int i = 0; i < N; ++i)
		{
			cin >> Coins[i];
		}
		cin >> M;
		Solve(N, Coins, M);
	}


	for (const int& Num : Fin)
	{
		cout << Num << endl;
	}

	return 0;
}