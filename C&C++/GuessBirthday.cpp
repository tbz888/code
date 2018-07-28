#include <iostream>
#include <cstdlib>
using namespace std;

char set[][53] = {
	"16 17 18 19\n 20 21 22 23\n 24 25 26 27\n 28 29 30 31",
	" 8  9 10 11\n 12 13 14 15\n 24 25 26 27\n 28 29 30 31",
	" 4  6  5  7\n 12 13 14 15\n 20 21 22 23\n 28 29 30 31",
	" 2  3  6  7\n 10 11 14 15\n 18 19 22 23\n 26 27 30 31",
	" 1  3  5  7\n  9 11 13 15\n 17 19 21 23\n 25 27 29 31",
	};

int main()
{
	int record = 0;
	bool value = 0;

	for (int i = 0; i < 5; ++i)
	{
		cout << set[i] << endl << endl;
		cout << "Is your birthday in the set?" << endl;
		cout << "	Please enter 1 or 0 :" << endl;
		cin >> value;

		system("cls");		

		record <<= 1;
		record |= value;
	}

	cout << "Your birthday : " << record << endl;
	system("pause");
	return 0;
}