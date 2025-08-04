#include <iostream>
#include <map>

using namespace std;

int main()
{
	map<int,int> m{};

	int N;

	cin >> N;


	int Num;

	auto iter = m.find(Num);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d",&Num);

		iter = m.find(Num);

		if (iter == m.end())
		{
			m.insert(make_pair(Num,1));
		}
		else
		{
			++(*iter).second;
		}
	}


	for (const auto& it : m)
	{
		for (int i = 0; i < it.second; ++i)
		{
			printf("%d\n", it.first);
		}
	}

	return 0;
}