#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main()
{

	int iNum[26]{};
	memset(iNum,-1,sizeof(iNum));
	string str{};
	cin >> str;

	for (size_t i = 0; i < str.size(); ++i)
	{
		int K = str[i] - 'a';
		if (iNum[K] == -1)
		{
			iNum[K] = i;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		cout << iNum[i] << " ";
	}

	return 0;
}