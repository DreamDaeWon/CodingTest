#include <iostream>
#include <vector>
using namespace std;


int check(int k , int n)
{

	if (n == 1)
	{
		return 1;
	}

	vector<vector<int>> Vec(k+1,vector<int>(n,1));

	// 0층 채우기
	for (int i = 0; i < n; ++i)
	{
		Vec[0][i] = i + 1;
	}


	for (int i = 1; i < k+1; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			Vec[i][j] = Vec[i - 1][j] + Vec[i][j - 1];
		}
	}
	return Vec[k][n - 1];
}


int main()
{
	int Case; // 케이스의 수


	int k; // 층
	int n; // 호

	cin >> Case;

	vector<pair<int, int>> AllVec(Case);

	for (int i = 0; i < Case; ++i)
	{
		cin >> AllVec[i].first >> AllVec[i].second;
	}

	for (int i = 0; i < Case; ++i)
	{
		cout << check(AllVec[i].first, AllVec[i].second) << endl;
	}

	return 0;
}