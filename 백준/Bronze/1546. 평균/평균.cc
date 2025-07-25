#include <iostream>
#include <vector>
#include <numeric>
using namespace std;



int main()
{
	int N;

	cin >> N;


	int Num{};

	vector<int> AllNum{};

	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &Num);
		AllNum.push_back(Num);
	}

	float MaxNum = *max_element(AllNum.begin(), AllNum.end());

	float AllSum = accumulate(AllNum.begin(), AllNum.end(), 0);

	cout << AllSum / MaxNum * 100.f / N << endl;

	return 0;
}