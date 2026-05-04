#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> dp(triangle.size());
    for (int i = 0; i < triangle.size(); ++i)
    {
        dp[i] = vector<int>(triangle[i].size(), 0);
    }

    // 마지막 줄 입력
    for (int i = triangle.size() - 1; i >= 0; --i)
    {
        for (int j = 0; j < dp[i].size(); ++j)
        {
            dp[i][j] = triangle[i][j];
        }
    }

    for (int i = triangle.size() - 2; i >= 0; --i)
    {
        for (int j = 0; j < dp[i].size(); ++j)
        {
            dp[i][j] = max(dp[i + 1][j] + triangle[i][j], dp[i + 1][j + 1] + triangle[i][j]);
        }
    }

    answer = dp[0][0];

    return answer;
}