#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main()
{
	int T{}; // 테스트 케이스 수
	std::cin >> T;

	std::vector<int> results(T, 0);

	for(int test = 0; test < T; ++test)
	{
		int N{}; // 주식 투자 일 수
		std::cin >> N;
		int result{};// 최대 이익
		std::vector<std::vector<int>> day_money(N,std::vector<int>(3,0));

		for (int i = 0; i < N; ++i)
		{
			for (int day = 0; day < 3; ++day)
			{
				int money{};
				std::cin >> money;
				day_money[i][day] = money;
			}
		}

		for(int day = 0; day < N; ++day)
		{
			int max_money = *std::max_element(day_money[day].begin(), day_money[day].end());
			if(max_money > 0)
			{
				result += max_money;
			}
		}

		results[test] = result;
	}

	for(int result : results)
	{
		std::cout << result << std::endl;
	}

	return 0;
}