#include <iostream>
#include <vector>

std::vector<std::vector<int>> board{};

std::vector<std::pair<int, int>> directions{
	{-1, -1}, {-1, 0}, {-1, 1},
	{0, -1},           {0, 1},
	{1, -1},  {1, 0},  {1, 1}
}; // 대각선 포함한 8방향

void recv_DFS(int x, int y)
{
	for(int i = 0; i< directions.size(); ++i)
	{
		int newX = x + directions[i].first;
		int newY = y + directions[i].second;
		if(newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && board[newX][newY] == 1)
		{
			board[newX][newY] = 0; // 방문 처리
			recv_DFS(newX, newY);
		}
	}
}


int main()
{
	std::vector<int> result{};

	int w{}, h{};
	while (true)
	{
		int count = 0;
		std::cin >> w >> h;
		if(w == 0 && h == 0)
		{
			break;
		}
		
		board.assign(h, std::vector<int>(w, 0));
		for(int i = 0; i < h; ++i)
		{
			for(int j = 0; j < w; ++j)
			{
				std::cin >> board[i][j];
			}
		}

		for (int i = 0; i < h; ++i)
		{
			for(int j = 0; j < w; ++j)
			{
				if(board[i][j] == 1)
				{
					recv_DFS(i, j);
					++count;
				}
			}
		}
		
		result.push_back(count);
	}

	for(int i = 0 ; i< result.size(); ++i)
	{
		std::cout << result[i] << std::endl;
	}


	return 0;
}