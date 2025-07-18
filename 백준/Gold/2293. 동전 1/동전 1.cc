#include <iostream>
#include <vector>

using namespace std;

vector<int> Final_Dp{};

vector<int> Now_Dp{};

vector<int> Coins{}; // 동전 금액

int Solve(int& N, vector<int>& Coins, int& M)
{
	// dp 만들기
	Final_Dp.resize(M + 1, 0);
	Now_Dp.resize(M + 1, 0);
	

	// 0번째 1로 채우기
	Final_Dp[0] = 1;
	Now_Dp[0] = 1;


	// 맨 윗 줄 구하기
	for (int i = 0; i < M + 1; ++i)
	{
		Final_Dp[i] = (int)(i % Coins[0] == 0);
	}


	// dp 채우기
	for (int i = 1; i < N; ++i)
	{
		fill(Now_Dp.begin(), Now_Dp.end(), 0);
		Now_Dp[0] = 1;

		for (int j = 1; j < M + 1; ++j)
		{
			if (Coins[i] > j) // 만약 아직 동전보다 돈이 작을경우
			{
				Now_Dp[j] = Final_Dp[j]; // 위에꺼가 최고답이니까 그대로
				continue;
			}
			Now_Dp[j] = Now_Dp[j - Coins[i]] + Final_Dp[j];
		}
		Final_Dp = Now_Dp;
	}
	// 답 구한것 넣기
	return Final_Dp[M];
}



int main()
{
	int N; // 동전의 가지 수

	int M; // 금액


	cin >> N;
	cin >> M;
	Coins.clear();
	Coins.resize(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> Coins[i];
	}

	cout << Solve(N, Coins, M) << endl;

	return 0;
}