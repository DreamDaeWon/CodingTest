#include<iostream>
#include <queue>
#include <unordered_set>


int main()
{
	int N{}, K{}; // 수빈, 동생
	std::cin >> N >> K;
	int result = 0; // 깊의 결과값

	std::queue<std::pair<int, int>> q;
	std::unordered_set<int> visited;
	q.push({ N,0 });
	while (!q.empty())
	{
		int a = q.front().first;
		int death = q.front().second;
		q.pop();

		// 방문 했으면 건너뛰기
		/*if(visited.find(a) != visited.end())
			continue;*/
		// 방문처리
		visited.insert(a);

		if (a == K)
		{
			result = death;
			break;
		}

		// 깊이 추가
		++death;

		// 경우의 수 3 가지 넣기
		if(a - 1 >= 0 && visited.find(a - 1) == visited.end())
		{
			q.push({ a - 1, death });
		}
		if(a + 1 <= 1000000 && visited.find(a + 1) == visited.end())
		{
			q.push({ a + 1, death });
		}
		if (a * 2 <= 1000000 && visited.find(a * 2) == visited.end())
		{
			q.push({ a * 2, death });
		}
	}

	std::cout << result << std::endl;
	return 0;
}