/***************************************************************
 *程序名称：2048
 *内容摘要：练习
 *其它说明：无
 *当前版本：V1.0
 *作    者：tbz
 *完成日期：2014年5月8日
 ***************************************************************/

#include <cstdlib>
#include <conio.h>
#include "Grid.h"
#include <iostream>
using namespace std;

bool isNeed(char c)
{
    switch (c)
    {
        case 'a':case 's':case 'd':case 'w':
        case 'A':case 'S':case 'D':case 'W':
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    Grid game;
    system("title 2048");
    system("mode con: cols=32 lines=10");
    
    //game flow control
    while (true)
    {
        system("cls");
        game.print();
        if (game.isWon())
        {
            cout << endl << "Congratulation!    You won!" << endl;
            cout << "Press any key to exit." << endl;
            int pause;
            cin >> pause;
            return 0;
        }

        if (game.isLost())
            break;

        //Promt
        cout << endl;
        cout << "A -> Left, D -> Right\nW -> Up, S -> Down." << endl;
        char input = getch();

        if (!isNeed(input))    continue;
        
        game.move(input);
    }

    cout << "Sorry! You lose." << endl;
    int pause;
    cin >> pause;
    return 0;
}