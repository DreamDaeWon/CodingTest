#include <iostream>
using namespace std;

int main()
{
	int iNum{};

	cin >> iNum;

	int iOutNum{1};
	while (iNum != 0)
	{
		printf("%d \n",iOutNum++);
		iNum--;
	}

	//
	//for (int i = 1; i <= iNum; ++i)
	//{
	//	cout << i << endl;
	//}

	return 0;
}