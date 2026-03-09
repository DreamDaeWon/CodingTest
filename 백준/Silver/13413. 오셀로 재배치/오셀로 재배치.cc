#include <iostream>
#include <vector>

using namespace std;

vector<char> stones{};
vector<char> Goalstones{};

int allstoneNum{};

int result{};

// 돌 색상 개수 맞추기
void Change()
{
	int whiteNum{};
	for (int i = 0; i < allstoneNum; ++i)
	{
		if (stones[i] == 'W')
		{
			++whiteNum;
		}
	}
	int GoalwhiteNum{};
	for (int i = 0; i < allstoneNum; ++i)
	{
		if (Goalstones[i] == 'W')
		{
			++GoalwhiteNum;
		}
	}

	if (whiteNum > GoalwhiteNum)
	{
		for (int i = 0; i < allstoneNum; ++i)
		{
			if (stones[i] != Goalstones[i] && stones[i] == 'W')
			{
				stones[i] = 'B';
				--whiteNum;
				++result;
				if (whiteNum == GoalwhiteNum)
				{
					break;
				}
			}
		}
	}
	else if (whiteNum < GoalwhiteNum)
	{
		for (int i = 0; i < allstoneNum; ++i)
		{
			if (stones[i] != Goalstones[i] && stones[i] == 'B')
			{
				stones[i] = 'W';
				++whiteNum;
				++result;
				if (whiteNum == GoalwhiteNum)
				{
					break;
				}
			}
		}
	}
}

void stoneSwap()
{
	for (int i = 0; i < allstoneNum; ++i)
	{
		if (stones[i] != Goalstones[i])
		{
			char temp = stones[i];
			for (int j = i + 1; j < allstoneNum; ++j)
			{
				if (stones[j] != Goalstones[j] && temp != stones[j])
				{
					swap(stones[i], stones[j]);
					++result;
					break;
				}
			}
		}
	}
}

bool Check()
{
	for (int i = 0; i < allstoneNum; ++i)
	{
		if(stones[i] != Goalstones[i])
			return false;
	}
	return true;
}

int main()
{
	int num{};
	cin >> num;

	
	for (int i = 0; i < num; ++i)
	{
		cin >> allstoneNum;
		
		stones.resize(100000);
		Goalstones.resize(100000);

		result = 0;
		// 입력 받기
		for (int j = 0; j < allstoneNum; ++j)
		{
			char stone;
			cin >> stone;
			stones[j] = stone;
		}

		// 정답 입력
		for (int j = 0; j < allstoneNum; ++j)
		{
			char stone;
			cin >> stone;
			Goalstones[j] = stone;
		}
		// 돌 개수 맞추기 -> 최대한 자리에 맞게
		Change();
		stoneSwap();
		if (Check())
		{
			cout << result << endl;
		}
	}

	return 0;
}