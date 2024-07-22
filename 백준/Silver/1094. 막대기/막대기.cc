#include <iostream>

using namespace std;

int main()
{
	int iBar{}; // 사용한 막대기 개수
	int iCm{}; // 현재 막대기의 길이

	int iWant{}; // 원하는 길이

	cin >> iWant;

	while (true)
	{
		++iBar;
		iCm = 64;

		if (iWant >= iCm) // 만약 원하는 길이가 막대기 보다 더 클 경우
		{
			iWant -= iCm;
		}
		else
		{
			while (true)
			{
				if (iWant < iCm)
				{
					iCm = iCm * 0.5;
				}

				if (iWant >= iCm)
				{
					iWant -= iCm;
					break;
				}
			}
		}


		if (iWant == 0) // 원하는 길이를 구했으면 나가기
		{
			break;
		}

	}


	cout << iBar << endl;
	return 0;
}