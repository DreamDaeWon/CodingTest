#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N{}; // 회의 수
	std::cin >> N;

	std::vector<std::pair<int, int>> meetings(N); // 회의 시작 시간과 종료 시간을 저장하는 벡터

	for(int i = 0 ; i < N; ++i)
	{
		std::cin >> meetings[i].first >> meetings[i].second;
	}

	std::sort(meetings.begin(), meetings.end(), [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
		if(a.second == b.second)
		{
			return a.first < b.first; // 종료 시간이 같으면 시작 시간이 빠른 순으로 정렬
		}
		return a.second < b.second;
		});

	int count{}; // 최대 회의 수
	int end_time{}; // 마지막 회의 종료 시간

	for(int i = 0; i < N; ++i)
	{
		if(meetings[i].first >= end_time)
		{
			++count;
			end_time = meetings[i].second;
		}
	}
	std::cout << count << std::endl;

}