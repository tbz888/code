/***************************************************************
 *程序名称：2048
 *内容摘要：练习
 *其它说明：无
 *当前版本：V1.0
 *作    者：tbz
 *完成日期：2014年5月8日
 ***************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include "Grid.h"
using namespace std;

//从1开始计数
int& Grid::at(int row, int column)
{
	return position[row-1][column-1];
}

//生成某范围的随机数
int Grid::random(int min, int max)
{
	return ((rand() % (max-min+1)) + min);
}

//建立4X4表格，并初始化
Grid::Grid()
{
	srand(time(0));
	for (int row = 1; row <= 4; ++row)
		for (int column = 1; column <= 4; ++column)
		{
			at(row, column) = 0;	
		}	

	//放置2个数
	generateEntry(2);
}

//生成几个数，不重复
void Grid::generateEntry(int count)
{
	int x = 0, y = 0, value = 0;
	for (int i = 0; i < count; ++i)
	{
		bool valid = false;
		while(!valid)
		{
			x = random(1, 4);
			y = random(1, 4);
			value = random(1, 2) * 2;
			if (!at(x, y))	
			{
				valid = true;
				at(x, y) = value;
			}
		}
	}
}

//视图绘制
void Grid::print()
{
	cout << " ------------2048------------" << endl;
	cout << " ____________________________" << endl;
	for (int i = 1; i <= 4; ++i)
	{
		cout << "|";
		for (int j = 1; j <= 4; ++j)
		{
			int temp = at(i, j);
			if (temp)
				cout << " " << setw(4) << temp << ". ";
			else
				cout << " " << setw(4) << ' ' << ". ";
		}

		cout << "|" << endl;
	}
	cout << " ----------------------------" << endl;
}

//按动作移动
void Grid::move(char action)
{
	bool moved = false;
	switch(action)
	{
		case 'a':
		case 'A':
			moved = moveLeft();
			break;
		case 'd':
		case 'D':
			moved = moveRight();
			break;
		case 'w':
		case 'W':
			moved = moveUp();
			break;
		case 's':
		case 'S':
			moved = moveDown();
			break;
	}
	if (moved)
		generateEntry(1);
}

//检测
bool Grid::isWon()
{
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (at(i, j) == 2048)
				return true;
		}
	}
	return false;
}

bool Grid::isExistEqual(int row, int column)
{
	bool ret = false;

	//行检测
	if (row == 1)
	{
		ret = (at(row, column) == at(row+1, column));
	}
	else if (row == 4)
	{
		ret = (at(row, column) == at(row-1, column));
	}
	else
	{
		ret = (at(row, column) == at(row-1, column)) || (at(row, column) == at(row+1, column));
	}

	if (ret == true)
		return true;

	//列检测
	if (column == 1)
	{
		ret = (at(row, column) == at(row, column+1));
	}
	else if (column == 4)
	{
		ret = (at(row, column) == at(row, column-1));
	}
	else
	{
		ret = (at(row, column) == at(row, column-1)) || (at(row, column) == at(row, column+1));
	}
	return ret;
}

bool Grid::isLost()
{
	for (int i = 1; i <= 4; ++i)
	{
		for (int j = 1; j <= 4; ++j)
		{
			if (!at(i, j))
				return false;
			else
			{
				if (isExistEqual(i, j))
					return false;
			}
		}
	}

	return true;
}

//下
bool Grid::moveDown()
{
	int top = 1, bottom = 4;
	bool moved = false;

	for (int column = 1; column <= 4; ++column)
	{
		//相同的数字合并
		int last = 0, pos = 0;
		for (int work = bottom; work >= top; --work)
		{
			if (at(work, column))
			{
				if (last)
					if (at(work, column) == last)
					{
						at(work, column) = 0;
						at(pos, column) *= 2;
						moved = true;
						last = 0;
						pos = 0;
					}
					else
					{
						last = at(work, column);
						pos = work;
					}
				else if (!last)
				{
					last = at(work, column);
					pos = work;
				}
			}
		}

		//将数字往栈底挤
		for (int work = bottom; work >= top; --work)
		{
			if (at(work, column))
			{
				for (int i = work; i <= bottom-1; ++i)
				{
					if (!at(i+1, column))
					{
						swap(at(i, column), at(i+1, column));
						moved = true;
					}
					else break;
				}
			}
		}
	}

	return moved;
}

//上
bool Grid::moveUp()
{
	int top = 4, bottom = 1;
	bool moved = false;

	for (int column = 1; column <= 4; ++column)
	{
		//相同的数字合并
		int last = 0, pos = 0;
		for (int work = bottom; work <= top; ++work)
		{
			if (at(work, column))
			{
				if (last)
					if (at(work, column) == last)
					{
						at(work, column) = 0;
						at(pos, column) *= 2;
						moved = true;
						last = 0;
						pos = 0;
					}
					else
					{
						last = at(work, column);
						pos = work;
					}
				else if (!last)
				{
					last = at(work, column);
					pos = work;
				}
			}
		}

		//将数字往底挤
		for (int work = bottom; work <= top; ++work)
		{
			if (at(work, column))
			{
				for (int i = work; i >= bottom+1; --i)
				{
					if (!at(i-1, column))
					{
						swap(at(i, column), at(i-1, column));
						moved = true;
					}
					else break;
				}
			}
		}
	}

	return moved;
}

//左
bool Grid::moveLeft()
{
	int top = 4, bottom = 1;
	bool moved = false;

	for (int row = 1; row <= 4; ++row)
	{
		//相同的数字合并
		int last = 0, pos = 0;
		for (int work = bottom; work <= top; ++work)
		{
			if (at(row, work))
			{
				if (last)
					if (at(row, work) == last)
					{
						at(row, work) = 0;
						at(row,pos) *= 2;
						moved = true;
						last = 0;
						pos = 0;
					}
					else
					{
						last = at(row, work);
						pos = work;
					}
				else if (!last)
				{
					last = at(row, work);
					pos = work;
				}
			}
		}

		//将数字往底挤
		for (int work = bottom; work <= top; ++work)
		{
			if (at(row, work))
			{
				for (int i = work; i >= bottom+1; --i)
				{
					if (!at(row, i-1))
					{
						swap(at(row, i), at(row, i-1));
						moved = true;
					}
					else break;
				}
			}
		}
	}

	return moved;
}


//右
bool Grid::moveRight()
{
	int top = 1, bottom = 4;
	bool moved = false;

	for (int row = 1; row <= 4; ++row)
	{
		//相同的数字合并
		int last = 0, pos = 0;
		for (int work = bottom; work >= top; --work)
		{
			if (at(row, work))
			{
				if (last)
					if (at(row, work) == last)
					{
						at(row, work) = 0;
						at(row,pos) *= 2;
						moved = true;
						last = 0;
						pos = 0;
					}
					else
					{
						last = at(row, work);
						pos = work;
					}
				else if (!last)
				{
					last = at(row, work);
					pos = work;
				}
			}
		}

		//将数字往底挤
		for (int work = bottom; work >= top; --work)
		{
			if (at(row, work))
			{
				for (int i = work; i <= bottom-1; ++i)
				{
					if (!at(row, i+1))
					{
						swap(at(row, i), at(row, i+1));
						moved = true;
					}
					else break;
				}
			}
		}
	}

	return moved;
}