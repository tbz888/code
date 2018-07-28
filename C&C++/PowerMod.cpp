#include <iostream>
#include <cmath>
using namespace std;

int power(int num)
{
	return num * num;
}

int powerMod(int a, int b, int c)
{
	if (a <= 0 || b < 0 || c <= 0)
		return -1;
	if (!b)	return 1;

	int ans = 1;
	if (b % 2)
		ans *= (a % c);
	return (ans * power(powerMod(a, b/2, c)) % c);
}

int main(int argc, char const *argv[])
{
	int a = 0, b = 0, c = 0;
	cout << "Please enter a,b,c such that (a^b mod c):" << endl;
	cin >> a >> b >> c;
	cout << powerMod(a, b, c);
	return 0;
}