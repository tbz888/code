#include <iostream>
using namespace std;

//n皇后的设定值
const int COLUMN = 8;
int queen[COLUMN];

/*判断当前列以上是否冲突，即对角线和列检查
 *而行数偏移量与对角线的关系，可以归纳得出
 */
bool isValid(int row, int col)
{
	for (int i = 1; i <= row; ++i)
	{
		if (queen[row - i] == col ||
			queen[row - i] == col - i || 
			queen[row - i] == col + i)
			return false;
	}
	return true;
}

/*回溯的步骤：（试走当前行 至 最后一行）
 *走一步，并检测是否冲突，
 *	若 合法，则 试走下一区域，
 *				若 成功，则 本区域试走成功
 *				若 失败，则 返回至上一区域，试走右一步
 * 	若 非法，则 试走右一步
 *
 * 边界处理->	若下一区域越界，就本区域试走成功
 *				若本行没有成功地试走一步，则本区域试走失败
 */
bool tryWalk(int row=0)
{
 	if (row >= COLUMN)	return true;
	for (int i = 0; i < COLUMN; ++i)
	{
	 	queen[row] = i;
		if ( isValid(row, i) && tryWalk(row + 1) )
			return true;
	}
	return false;
}

void printGrid()
{
	for (int j = 0; j < COLUMN; ++j)
	{
		for (int k = 0; k < COLUMN; ++k)
		{	if (k == queen[j])
				cout << " $ |";
			else 
				cout << "   |";
		}
		cout << endl;
	}
	for (int j = 0; j < COLUMN; ++j)
		cout << "~~~~";
	cout << endl;
}

int main(int argc, char const *argv[])
{
 	if ( tryWalk() )
 		printGrid();
 	else 
 		cout << "No solution!" << endl;
	return 0;
}
