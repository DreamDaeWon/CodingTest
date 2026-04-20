#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int N{}; // 소의 마리 수

	std::cin >> N;

	std::vector<std::pair<int, int>> allCow(N, {0,0}); // 모든 소의 {입장시간, 검문시간}

	for (int i = 0; i < N; ++i)
	{
		std::cin >> allCow[i].first >> allCow[i].second;
	}

	std::sort(allCow.begin(), allCow.end(), [](const std::pair<int,int>& a, const std::pair<int, int>& b) {
		return a.first < b.first;
		});


	int result{}; // 총 걸리는 시간
	for (int i = 0; i < N; ++i)
	{
		if (result < allCow[i].first) // 앞 소까지 검사 다 끝났는데 아직 다음 소 도착 전이면?
		{
			result += allCow[i].first - result; // 차이만큼 시간 초 더해주기
			result += allCow[i].second; // 차이만큼 시간 초 더해주기
		}
		else // 같거나 역전인 경우
		{
			result += allCow[i].second; // 그냥 검수 시간만 더해주면 된다.
		}
	}

	std::cout << result << std::endl;

	return 0;
}