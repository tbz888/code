#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*   存储状态的字符串中，
        下标: [0]表示农夫的位置, [1]表示白菜的位置, [2]表示羊的位置, [3]表示狐狸的位置;
        值:   '0' 表示在此岸， '1' 表示在对岸
 */
vector<string> state;
bool isVisited[16] = {false};

bool getBool(char c)                            // 字符转换为真假值
{
    return (c-'0') ? true : false;
}

string reverseBit(string str, int index)        // 改变串中的某一位，index为下标
{
    if (str[0] == '1')
        str[0] = '0';
    else
        str[0] = '1';
   
   if (index > 0)
   {
        if (str[index] == '1')
            str[index] = '0';
        else
            str[index] = '1';
    }
    return str;
}

int toInt(string str)                            // 只含0、1的字符串，转换为整数
{
    return  (str[0]-'0') * 8 + (str[1]-'0') * 4 + (str[2]-'0') * 2 + (str[3]-'0') * 1;
}

void dfs(string currentState)
{
    int number = toInt(currentState);
    if (isVisited[number]) return;      // 已访问，则返回

    do
    {
        state.push_back(currentState);  // 搜索过程的状态记录
        isVisited[number] = true;

        if (currentState == "1111")     // 发现解
        {                               // 打印解
            for (vector<string>::iterator i = state.begin(); i != state.end(); ++i)
            {
                cout << *i;
                if (i+1 != state.end())
                    cout << " -> ";
            }
            cout << endl;
            break;
        }

        // 限制条件： 农夫不在时，3个东西之间不存在捕食关系
        if ( ( ( getBool(currentState[1]) xor getBool(currentState[2]) == false ) && (currentState[2] != currentState[0]) )
          || ( ( getBool(currentState[3]) xor getBool(currentState[2]) == false ) && (currentState[2] != currentState[0]) ) )   break;  
        
        dfs( reverseBit(currentState, 0) );     // 农夫空手过河
        for (int i = 1; i < 4; ++i)             // 农夫尝试带一个东西过河
        {
            if (currentState[i] == currentState[0])     // 保证农夫和物品在同一岸
                dfs( reverseBit(currentState, i) );
        }


    } while(0);

    state.pop_back();                       // 清楚记录
    isVisited[number] = false;              
    return;
}

int main(int argc, char const *argv[])
{
    dfs("0000");        // 初始状态
    return 0;  
}