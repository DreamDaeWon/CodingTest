#include<iostream>
using namespace std;


int main()
{
	int Input{};

	int iResult{1};

	int Six{6};

	cin >> Input;

	--Input;


	if(Input != 0)
	{
		while (true)
		{
			Input -= Six;

			Six += 6;

			++iResult;

			if (Input <= 0)
			{
				break;
			}
		}
	}
	
	cout << iResult;

	return 0;
}