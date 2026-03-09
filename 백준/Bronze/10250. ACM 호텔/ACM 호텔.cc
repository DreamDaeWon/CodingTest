#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	int TastCase{};

	int H{}, W{}, N{}; // 각 호텔의 층수, 방수, 몇 번째로 온 손님인지?

	cin >> TastCase;

	vector<string> AllResult{};

	for (int i = 0; i < TastCase; ++i)
	{
		cin >> H >> W >> N;

		int iOut = 0;

		//cout << (int)(N / H) + 1;
		string Result = {};

		Result = to_string((int)(N % H));

		if (stoi(Result) == 0)
		{
			Result = to_string(H);
		}

		

	
		if ((int)(N % H) == 0)
		{
			if ((N / H) < 10)
			{
				//cout << 0;
				Result = Result + "0";
			}
			Result += to_string((int)(N / H));
		}
		else
		{
			if ((N / H) + 1 < 10)
			{
				//cout << 0;
				Result = Result + "0";
			}
			Result += to_string((int)(N / H) + 1);
		}

		AllResult.push_back(Result);
	}


	for (int i = 0; i < TastCase; ++i)
	{
		cout << AllResult[i] << endl;
	}

	return 0;
}