/*Problem: 由于键盘错位敲出的字符串，请帮忙矫正
 *Input:	KK G:U Hppf Kpn
 *Output: 	JJ FLY Good Job
 */

#include <iostream>
#include <cstring>
using namespace std;

// 常量表，免去一堆的switch  (复杂度依旧)
const char switchTable[] = "1234567890qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
int len = strlen(switchTable);

int position(char c)
{
	for (int i = 0; i < len; ++i)
		if (c == switchTable[i])
			return i;
}

int main(int argc, char const *argv[])
{
 	char str[100] = {0};
 	cin.getline(str, 100);

 	for (int j = 0; str[j]; ++j)
 	{
 		str[j] = switchTable[position(str[j]) - 1];
		cout << str[j];
 	}
	cout << endl;
 	return 0;
}