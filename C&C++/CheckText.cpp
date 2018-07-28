#include <iostream>
#include <fstream>
using namespace std;

/*Funtionality:
determine if two file text is the same.
Otherwise, point out the first difference position
*/

// method: compare the character from the two filestream meanwhile
int main(int argc, char const *argv[])
{
	int currentRow = 0;
	ifstream file1, file2;
	char buffer1[300], buffer2[300];
	file1.open(argv[1]);
	file2.open(argv[2]);

	while (!(file1.eof() && file2.eof())){	
		++currentRow;
		file1.getline(buffer1, 300);
		file2.getline(buffer2, 300);
		for (int i = 0; buffer1[i] || buffer2[i]; ++i){
			if (buffer2[i] != buffer1[i]){
			   cout << "Difference(count from 1) : in Row   " << currentRow << "	Colum  " << i + 1 << endl;
			   goto Exit; // a tricky
			}
		}
	}	
	cout << "Text1 equals to Text2, completed." << endl;
Exit:
	file1.close();
	file2.close();
	return 0;
}