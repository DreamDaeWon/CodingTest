#include<iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

// 정점 번호가 작은 것을 먼저 방문
// 정점 번호는 1번부터
// 주어지는 간선은 양방향

std::vector<std::vector<int>> graph{};
std::vector<bool> visited{};


void BFS(int start)
{
	std::stack<int> s;
	s.push(start); // 시작 노드를 스택에 추가

	for (int i = 0; i < visited.size(); ++i)
	{
		std::sort(graph[i].begin(), graph[i].end(), std::greater<int>()); // 내림차순으로 정렬
	}


	int current{};
	while (s.empty() == false)
	{
		current = s.top();
		s.pop();

		if (visited[current] == false)
		{
			std::cout << current << " ";
		}

		visited[current] = true;
		
		for (int i = 0; i < graph[current].size(); ++i)
		{
			int next = graph[current][i];
			if(visited[next] == false)
			{
				s.push(next);
			}
		}
	}
}

void DFS(int start)
{
	for (int i = 0; i < visited.size(); ++i)
	{
		std::sort(graph[i].begin(), graph[i].end()); // 오름차순으로 정렬
	}

	std::queue<int> q;
	q.push(start); // 시작 노드를 큐에 추가

	while (q.empty() == false)
	{
		int current = q.front();
		q.pop();

		if (visited[current] == false)
		{
			std::cout << current << " ";
		}

		visited[current] = true;
		for(int i = 0; i < graph[current].size(); ++i)
		{
			int next = graph[current][i];
			if(visited[next] == false)
			{
				q.push(graph[current][i]);
			}
		}
	}

}

int main()
{
	int N{}; // 정점의 개수
	int	M{}; // 간선의 개수
	int start{}; // 탐색을 시작할 정점 번호
	
	std::cin >> N >> M >> start;

	graph.resize(N + 1); // 정점 번호가 1번부터 시작하므로 N+1 크기로 그래프 벡터를 초기화
	visited.resize(N + 1, false); // 방문 여부 벡터도 N+1 크기로 초기화
	for(int i = 0; i < N+1; ++i)
	{
		std::vector<int> temp(N, 0);
		graph.push_back(temp);
	}


	int temp1{}, temp2{};

	for (int i = 0; i < M; ++i)
	{
		std::cin >> temp1 >> temp2;
		graph[temp1].push_back(temp2);
		graph[temp2].push_back(temp1);
	}

	// BFS, DFS 수행
	BFS(start);
	std::cout << std::endl;


	visited.assign(N + 1, false); // 방문 여부 초기화
	DFS(start);

	return 0;
}