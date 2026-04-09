#include <iostream>
#include <string>

int main()
{
	int N{};
	std::string str{};

	std::cin >> N;

	std::cin >> str;

	size_t bonus{}; // 보너스 점수

	size_t result{}; // 결과 점수

	for (int i = 0; i < N; ++i)
	{
		if (str[i] == 'O')
		{
			result += bonus;
			++bonus;
			result += (i + 1);
		}
		else
		{
			bonus = 0;
		}
	}

	std::cout << result << std::endl;

	return 0;
}