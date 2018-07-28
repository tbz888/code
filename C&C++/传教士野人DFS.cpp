#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
 
int k = 2;                         // 船的长度k < N
bool bank = true;                 // true:右岸，false:左岸
vector<string> visited;           // 记录访问过的状态
 
bool dfs(int M, int C, int m, int c)   // 返回值表示成功与否
{
/*判断*/
    if(M<0 || C<0 || m<0 || c<0)     //非法
        return false;
    if( (M && C>M) || (m && c>m) )   //野人吃传教士
        return false;
     
    if( (bank && M==0 && C==0) ||
        (!bank && m==0 && c==0) )    // 全部过岸
        return true;
 
    // 判读是否已被遍历
    char record[30];
    if( !bank )
        sprintf(record, "M=%d,C=%d,m=%d,c=%d,boat=left", M,C,m,c);
    else
        sprintf(record, "M=%d,C=%d,m=%d,c=%d,boat=right", m,c,M,C);
    string str(record);
    for(int i = 0; i < visited.size(); ++i)
        if(visited[i] == str)                    
            return false;
 
    visited.push_back(str);
    bank = !bank;       // 假定成功了，修改岸的编号
                
    for (int x1 = 0; x1 < k; ++x1)
    {
        for (int x2 = 0; x2 < k; ++x2)
        {
        if (x1 + x2 <= k)
            if( dfs( m+x1, c+x2, M-x1, C-x2) )    //每次参数互换，可以实现改变对岸的情况，而不用依赖bank
            {  
                printf("Process: ");
                printf("运走%d个传教士和%d个野人\n", x1, x2);
                printf("State: ");
                printf("%s\n",record);
                return true;
            }
        }
    }

    bank = !bank;       // 失败了，复原岸的编号
    visited.pop_back();
    return false;
}
 
int main()
{
    char record[30];
    int M=3, C=3;       // 可自定义M, C
    int m=0, c=0;
    printf(" M为左岸传教士人数, C为左岸野人人数\n m为右岸传教士人数，c为右岸野人人数\n");
    printf("State: ");
    sprintf(record, "M=%d,C=%d,m=%d,c=%d,boat=left", M, C, m, c);
    printf("%s\n", record);
    if(!dfs(M,C,0,0))
        printf("No solution.\n");
    return 0;
}