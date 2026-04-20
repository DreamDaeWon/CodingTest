#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

	vector<float> failRate(N, 0);
	vector<int> failCount(N, 0);

	sort(stages.begin(), stages.end());

	for (int i = 0; i < stages.size(); ++i)
	{
		if(stages[i] > N)
		{
			continue;
		}
		failCount[stages[i] - 1]++;
	}

	int nowTryCount = stages.size();

	for (int i = 0; i < N; ++i)
	{
		if (failCount[i] > 0)
		{
			failRate[i] = static_cast<float>(failCount[i]) / nowTryCount;
		}
		nowTryCount -= failCount[i];
	}
	

	vector<pair<float, int>> failRateWithStage;
	for (int i = 0; i < N; ++i)
	{
		failRateWithStage.push_back({ failRate[i], i + 1 });
	}


	sort(failRateWithStage.begin(), failRateWithStage.end(), [](const pair<float, int>& a, const pair<float, int>& b) {
		if(a.first == b.first)
		{
			return a.second < b.second;
		}
		return a.first > b.first;
		});

	for (auto& element : failRateWithStage)
	{
		answer.push_back(element.second);
	}

    return answer;
}