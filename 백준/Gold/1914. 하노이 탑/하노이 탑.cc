#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void hanoi(int num, int from, int mid, int end)
{
	if (num == 1)
	{
		printf("%d %d\n", from, end);
		//cout << from << " " << end << endl;
		return;
	}
	hanoi(num - 1, from, end, mid); // 위에거 옮기기
	printf("%d %d\n", from, end);
	//cout << from << " " << end << endl;
	hanoi(num - 1, mid, from, end); // 중간에서 맨 마지막으로
}


int main()
{
	int Num{};

	cin >> Num;
	string AllNum = to_string(pow(2, Num));
	size_t iter = AllNum.find(".");

	AllNum = AllNum.substr(0,iter);

	AllNum[iter - 1] -= 1;

	cout << AllNum << endl;

	if (Num > 20)
	{
		return 0;
	}
	
	hanoi(Num,1,2,3);

	return 0;
}