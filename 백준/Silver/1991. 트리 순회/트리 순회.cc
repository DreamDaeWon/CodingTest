#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<char>> graph(26, std::vector<char>{});

std::vector<bool> visited(26, false);

std::vector<char> result{};


void recv_DFS(char Now)
{
	if (false == visited[Now - 'A'])
	{
		result.push_back(Now);
		visited[Now - 'A'] = true;
	}

	for(size_t i = 0 ; i < graph[Now - 'A'].size(); ++i)
	{
		if(graph[Now - 'A'][i] != '.')
			recv_DFS(graph[Now - 'A'][i]);
	}
}

void recv_Middle_DFS(char Now) // 중위순회
{
	if(graph[Now - 'A'][0] != '.')
	{
		recv_Middle_DFS(graph[Now - 'A'][0]);
	}

	if (false == visited[Now - 'A'])
	{
		result.push_back(Now);
		visited[Now - 'A'] = true;
	}

	if (graph[Now - 'A'][1] != '.')
	{
		recv_Middle_DFS(graph[Now - 'A'][1]);
	}
}

void recv_Last_DFS(char Now) // 후위순회
{
	for (size_t i = 0; i < graph[Now - 'A'].size(); ++i)
	{
		if (graph[Now - 'A'][i] != '.')
			recv_Last_DFS(graph[Now - 'A'][i]);
	}

	if (false == visited[Now - 'A'])
	{
		result.push_back(Now);
		visited[Now - 'A'] = true;
	}
}


int main()
{
	int N{};
	std::cin >> N;

	char nowAlphabet{};

	char temp{};

	for (int i = 0; i < N; ++i)
	{
		// 현재 노드 정보 입력받기
		std::cin >> nowAlphabet;

		// 두 번 입력받기 (왼쪽 자식 오른쪽 자식)
		std::cin >> temp;
		graph[nowAlphabet - 'A'].push_back(temp);


		std::cin >> temp;
		graph[nowAlphabet - 'A'].push_back(temp);

	}


	// 전위 순회
	recv_DFS('A');

	for (size_t i = 0; i < result.size(); ++i)
	{
		std::cout << result[i];
	}
	std::cout << std::endl;
	visited.assign(26,false);
	result.clear();



	// 중위순회
	recv_Middle_DFS('A');

	for (size_t i = 0; i < result.size(); ++i)
	{
		std::cout << result[i];
	}
	std::cout << std::endl;
	visited.assign(26, false);
	result.clear();



	// 후위순회
	recv_Last_DFS('A');

	for (size_t i = 0; i < result.size(); ++i)
	{
		std::cout << result[i];
	}
	std::cout << std::endl;

	return 0;
}