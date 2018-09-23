/***************************************************************
 *程序名称：2048
 *内容摘要：练习
 *其它说明：无
 *当前版本：V1.0
 *作    者：tbz
 *完成日期：2014年5月8日
 ***************************************************************/

#ifndef _GIRD_H_
#define _GIRD_H_

//实现4X4的方格，并提供移动、检测输赢等操作
class Grid
{
public:
	explicit Grid();
	
	void print();

	void move(char action);
	
	bool isWon();
	bool isLost();

private:
	int position[4][4];

	//这四个函数原理一致
	bool moveLeft();
	bool moveRight();
	bool moveUp();
	bool moveDown();
	
	//辅助函数
	bool isExistEqual(int row, int column);
	void generateEntry(int count);
	int& at(int row, int column);
	int random(int min, int max);
};

#endif