#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strSentence{};

	cin >> strSentence;
	for (int i = 0; i < strSentence.length(); ++i)
	{
		if (strSentence[i] >= 'A' && strSentence[i] <= 'Z')
		{
			strSentence[i] = strSentence[i] + 32;
		}
		else if (strSentence[i] >= 'a' && strSentence[i] <= 'z')
		{
			strSentence[i] = strSentence[i] - 32;
		}
	}
	cout << strSentence<< endl;

	return 0;
}