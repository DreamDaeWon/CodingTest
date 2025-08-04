#include <iostream>
#include <vector>

using namespace std;

vector<int> vec{};

bool Total{};

bool Plus(int 자리수, int 최대숫자)
{
	++vec[자리수];

	if (vec[자리수] > 최대숫자)
	{
		if (0 == 자리수)
		{
			vec[자리수] -= 1;
			return true;
		}

		Total = Plus(자리수 - 1, 최대숫자);
		vec[자리수] = vec[자리수 - 1];
	}
	return Total;
}


int main()
{
	int N; // 자연수 범위
	int Mum; // 자연수 개수

	cin >> N >> Mum;

	vec.resize(Mum, 1);


	bool Out{};

	while (!Out)
	{
		for(const int& num : vec)
		{
			printf("%d ", num);
		}
		printf("\n");

		Out = Plus(Mum - 1, N);
	}

	return 0;
}