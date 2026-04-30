#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;

    vector<int> dp(money.size(), 0);
    dp[0] = money[0];
    dp[1] = max(money[0], money[1]);

    for (int i = 2; i < money.size(); ++i)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + money[i]);
    }

    vector<int> dp1(money.size(), 0);
    dp1[0] = 0;
    dp1[1] = money[1];

    for (int i = 2; i < money.size(); ++i)
    {
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    }


    answer = max(dp[money.size() - 2], dp1[money.size() - 1]);

    return answer;
}
