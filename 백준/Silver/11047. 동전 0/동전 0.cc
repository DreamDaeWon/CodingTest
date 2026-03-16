#include <iostream>
#include <vector>
#include <ranges>

int main()
{
	int N{}; // 동전종류의 개수
	int K{}; // 목표 금액
	std::vector<int> coins{}; // 동전의 종류 모음
	int result{}; // 결과값
	std::cin >> N;
	std::cin >> K;

	int temp{};
	for (int i = 0; i < N; ++i)
	{
		std::cin >> temp;
		coins.push_back(temp);
	}

	for (int i = coins.size() - 1; i >= 0; --i)
	{
		result += K / coins[i];
		K = K % coins[i];
		if (K == 0)
		{
			break;
		}
	}
	std::cout << result;

}