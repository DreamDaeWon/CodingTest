#include <iostream>
#include <vector>
#include <cmath>

int main()
{
	int N{}; // 카드의 개수
	int M{}; // 가깝게 만들어야 하는 기준
	std::vector<int> cards{}; // 카드들의 숫자
	std::cin >> N;
	std::cin >> M;

	std::vector<int> allway{}; // 모든 경우의 수

	cards.reserve(N);

	int temp{};
	for (int i = 0; i < N; ++i)
	{
		std::cin >> temp;
		cards.push_back(temp);
	}

	for (int i = 0; i < cards.size()-2; ++i)
	{
		for (int j = i+1; j < cards.size()-1; ++j)
		{
			for (int k = j+1; k < cards.size(); ++k)
			{
				allway.push_back(cards[i] + cards[j] + cards[k]);
			}
		}
	}

	int result{}; // 결과

	int test{400000000}; // 테스트

	for (int& i : allway)
	{
		if (i <= M && test > std::abs(i - M))
		{
			test = std::abs(i - M);
			result = i;
		}
	}

	std::cout << result << std::endl;

}