#include <iostream>
using namespace std;

void permutation(int list[], int startIndex, int endIndex)
{
	if (startIndex == endIndex)
	{
		for (int i = 0; i <= endIndex; ++i)
			cout << list[i] << " ";
		cout << endl;
		return;
	}
	for (int i = startIndex; i <= endIndex;++i)
	{
		swap(list[startIndex], list[i]);
		permutation(list, startIndex + 1, endIndex);
		swap(list[startIndex], list[i]);
	}
}

int main()
{
	int list[] = {1, 2, 3, 4, 5};
	permutation(list, 0, sizeof(list)/sizeof(int) - 1);
}