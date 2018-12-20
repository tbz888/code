#include <stdio.h>
#include <vector>
#include <math.h>
#include <string>
using namespace std;
 
int k = 4;                         // 船的长度k < N
bool bank = true;                 // true:右岸，false:左岸
vector<string> visited;           // 记录访问过的状态
 
bool heuristicDfs(int M, int C, int m, int c)   // 返回值表示成功与否
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

/*启发性信息，并依据此信息来搜索*/
    int delta = bank ? abs(M-C) : abs(m-c);    // 右岸中传教士与野人的差值
 
    visited.push_back(str);
    bank = !bank;       // 假定成功了，修改岸的编号

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    int delta1 = delta;
    while (delta1 >= 0)                      // 从delta+1往前递减搜索
    {
        for (int x1 = 0; x1 < k; ++x1)          
        {
            int x2 = x1 + delta1;
            if (x1 + x2 <= k && x1 >= x2)
            {
                if( heuristicDfs( m+x1, c+x2, M-x1, C-x2) )    
                {  
                    printf("Process: ");
                    printf("运走%d个传教士和%d个野人\n", x1, x2);
                    printf("State: ");
                    printf("%s\n",record);
                    return true;
                }
                if (delta1 != 0)
                {
                    if( heuristicDfs( m+x2, c+x1, M-x2, C-x1) )    
                    {  
                        printf("Process: ");
                        printf("运走%d个传教士和%d个野人\n", x2, x1);
                        printf("State: ");
                        printf("%s\n",record);
                        return true;
                    }
                }
            }
        }
        --delta1;
    }

    delta1 = delta+1;          
    while (delta1 <= k)                     // 从delta+1往后递增搜索
    {
        for (int x1 = 0; x1 < k; ++x1)     
        {
            int x2 = x1 + delta1;
            if (x1 + x2 <= k && x1 >= x2)
            {
                if( heuristicDfs( m+x1, c+x2, M-x1, C-x2) )    
                {  
                    printf("Process: ");
                    printf("运走%d个传教士和%d个野人\n", x1, x2);
                    printf("State: ");
                    printf("%s\n",record);
                    return true;
                }
                if (delta1 != 0)
                {
                    if( heuristicDfs( m+x2, c+x1, M-x2, C-x1) )    
                    {  
                        printf("Process: ");
                        printf("运走%d个传教士和%d个野人\n", x2, x1);
                        printf("State: ");
                        printf("%s\n",record);
                        return true;
                    }
                }
            }
        }
        ++delta1;
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    bank = !bank;       // 失败了，复原岸的编号
    visited.pop_back();
    return false;
}
 
int main()
{
    char record[30];
    int M=5, C=5;       // 可自定义M, C
    int m=0, c=0;
    printf(" M为左岸传教士人数, C为左岸野人人数\n m为右岸传教士人数，c为右岸野人人数\n");
    printf("State: ");
    sprintf(record, "M=%d,C=%d,m=%d,c=%d,boat=left", M, C, m, c);
    printf("%s\n", record);
    if(!heuristicDfs(M,C,0,0))
        printf("No solution.\n");
    return 0;
}