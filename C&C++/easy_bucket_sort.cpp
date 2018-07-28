#include <iostream>
#include <memory.h>
using namespace std;

//just demo, so there isn't more function
int main(int argc, char const *argv[])
{
	int value[] = {9, 1, 8, 3, 3, 4, 6};

	int min = value[0], max = value[0];
	for (int i = 0; i < 7; ++i)		//get the min and max
	{							   //to ensure the amount of buckets
		if(value[i] > max)
			max = value[i];

		if(value[i] < min)
			min = value[i];
	}

	int* p = new int[1 + max - min];
	if (p == NULL)	return 0;
	memset(p, 0, (1 + max - min) * sizeof(int));
	for (int i = 0; i < 7; ++i)		//throw in bucket
	{
		++p[value[i] - min];
	}
		
	for (int i = 0; i < 1 + max - min; ++i)		//get the result
	{
		if (p[i])
		{
			for (int j = 0; j < p[i]; ++j)
				cout << i+1 << " ";
		}
	}
	cout << endl;
	
	delete[] p;
	p = NULL;
	return 0;
}
