#include <iostream>
#include <vector>
#include <algorithm>

int R{}; // 세로
int C{}; // 가로

std::vector<bool> visited(26, false); // 알파벳 방문 여부
std::vector<std::vector<bool>> visited_board{}; // 보드판

void recv_DFS_Back(int& result,std::vector<std::pair<int,int>>& track, std::vector<char>& road,std::vector<std::vector<char>>& board)
{

	std::pair<int, int> current = track.back();

	std::vector<std::pair<int, int>> directions =
	{ 
		{current.first - 1,current.second}, 
		{current.first + 1,current.second}, 
		{current.first ,current.second -1}, 
		{ current.first,current.second + 1}
	}; // 상하좌우


	track.push_back({-1,-1});
	road.push_back('-');

	for (int i = 0; i < directions.size(); ++i)
	{
		if(directions[i].first >= 0 && directions[i].first < R && directions[i].second >= 0 && directions[i].second < C) // 범위 안이라면?
		{
			if (!visited[board[directions[i].first][directions[i].second] - 'A']) // 만약 지금까지 지나온 알파벳 중에 가려는 알파벳이 없다면?
			{
				if (!visited_board[directions[i].first][directions[i].second]) // 만약 지금까지 지나온 경로 중에 가려는 경로가 없다면?
				{
					track.back() = directions[i];
					road.back() = board[directions[i].first][directions[i].second];
					visited[board[directions[i].first][directions[i].second] - 'A'] = true;
					visited_board[directions[i].first][directions[i].second] = true;
					recv_DFS_Back(result, track, road, board);
					visited[road.back() - 'A'] = false; // 다시 돌리기
					visited_board[track.back().first][track.back().second] = false; // 다시 돌리기
					track.back() = {-1,-1}; // 다시 돌리기
					road.back() = '-'; // 다시 돌리기
					
				}
			}
		}
	}

	if (result < road.size())
	{
		result = road.size() - 1;
	}

	track.pop_back();
	road.pop_back();
}

int main()
{
	std::cin >> R >> C;

	for(int i = 0; i < R; ++i)
	{
		std::vector<bool> temp(C, false);
		visited_board.push_back(temp);
	}

	std::vector<std::vector<char>> board(R, std::vector<char>(C));

	std::vector<char> road{};

	int result{};
	std::vector<std::pair<int, int>> track{}; // 지나온 경로


	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			std::cin >> board[i][j];
		}
	}
	visited[board[0][0] - 'A'] = true; // 시작점 방문 처리
	visited_board[0][0] = true; // 시작점 방문 처리
	road.push_back(board[0][0]);
	track.push_back({ 0,0 });

	recv_DFS_Back(result, track, road, board);

	std::cout << result;

	return 0;
}