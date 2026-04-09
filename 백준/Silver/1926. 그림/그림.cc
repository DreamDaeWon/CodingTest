#include <iostream>
#include <vector>

std::vector<std::vector<int>> board{};

int largestSize{};

int nowSize{};

void CheckBoard(int x, int y)
{
	std::vector<std::pair<int, int>> directions{
		{-1, 0},
		{1, 0},
		{0, -1},
		{0, 1}
	}; // 대각선 포함하지 않은 4방향

	if (board[x][y] == 1)
	{
		++nowSize;
	}

	board[x][y] = 0; // 방문 처리

	for (int i = 0; i < directions.size(); ++i)
	{
		int newX = x + directions[i].first;
		int newY = y + directions[i].second;
		if (newX >= 0 && newX < board.size() && newY >= 0 && newY < board[0].size() && board[newX][newY] == 1)
		{
			CheckBoard(newX, newY);
		}
	}
}




int main()
{
	int N{}, M{};

	std::cin >> N >> M;

	board.assign(N, std::vector<int>(M, 0));

	int temp{};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			std::cin >> temp;
			board[i][j] = temp;
		}
	}

	int result{};

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if(board[i][j] == 1)
			{
				CheckBoard(i, j);
				if (nowSize > largestSize)
				{
					largestSize = nowSize;
				}
				nowSize = 0;
				++result;
			}
		}
	}

	std::cout << result << std::endl;
	std::cout << largestSize << std::endl;

	return 0;
}
