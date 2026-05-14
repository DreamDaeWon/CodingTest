#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    vector<vector<int>> dp(n,vector<int>(m,0));
    vector<vector<int>> puddle_map(n,vector<int>(m,0)); // 웅덩이 표

    for (int i = 0; i < puddles.size(); ++i)
    {
        puddle_map[puddles[i][1] - 1][puddles[i][0] - 1] = 1;
    }

    // dp[n][m] = dp[n-1][m] + dp[n][m - 1]

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (i > 0 && j > 0)
            {
                if (puddle_map[i - 1][j] == 1) // 위에가 웅덩이었다면?
                {
                    if (puddle_map[i][j - 1] == 1) // 왼쪽도 웅덩이었다면?
                    {
                        dp[i][j] = 0; // 둘 다 웅덩이라 0임
                    }
                    else // 왼쪽은 웅덩이가 아니라면?
                    {
                        dp[i][j] = dp[i][j - 1] % 1000000007; // 왼쪽만
                    }
                }
                else if (puddle_map[i][j - 1] == 1) // 위에는 웅더잉가 아니고 아래가 웅덩이라면?
                {
                    dp[i][j] = dp[i - 1][j] % 1000000007; // 위쪽만
                }
                else // 둘 다 웅덩이가 아니라면?
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007; // 위 + 왼쪽
                }               
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else if (i == 0 && j > 0)
            {
                if (puddle_map[i][j - 1] == 1) // 왼쪽이 웅덩이었다면?
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i][j - 1] % 1000000007;
                }
            }
            else if (i > 0 && j == 0)
            {
                if (puddle_map[i - 1][j] == 1) // 왼쪽이 웅덩이었다면?
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] % 1000000007;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    answer = dp[n-1][m-1] % 1000000007;
    return answer;
}