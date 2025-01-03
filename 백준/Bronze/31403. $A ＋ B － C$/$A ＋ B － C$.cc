#include <iostream>
#include <string>

using namespace std;

int main()
{
	string A{};
	string B{};
	int C{};

	

	cin >> A >> B >> C;


	cout << stoi(A) + stoi(B) - C << endl;

	string ASumB = A + B;

	cout << stoi(ASumB) - C << endl;

	return 0;
}