//题意挺难理解的，大概就是说给两个数组，先求在同一位置，且值一样的个数，之后排除掉这些，求值相等，位置不等的对数，模拟就可以了
#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 1001;
using namespace std;
int secret[MAXN];
int guess[MAXN];
bool vis_s[MAXN];
bool vis_g[MAXN];
int num1[10];
int num2[10];
bool shuru(int N)
{
    for(int i = 0;i < N;i++)
    {
        scanf("%d",&guess[i]);
    }
    if(guess[0])
        return true;
    else
        return false;
}

int main()
{
    int Game = 1;
    int N;
    while(scanf("%d",&N) && N)
    {
        printf("Game %d:\n",Game++);
        for(int i = 0; i < N; i++)
        {
            scanf("%d",&secret[i]);
        }
        while(shuru(N))
        {
            memset(num1,0,sizeof(num1));
            memset(num2,0,sizeof(num2));
            memset(vis_g,0,sizeof(vis_g));
            memset(vis_s,0,sizeof(vis_s));
            int first = 0;
            for(int i = 0; i < N; i++)
            {
                if(guess[i] == secret[i])
                {
                    first++;
                    vis_g[i] = 1;
                    vis_s[i] = 1;
                }
            }
            int second = 0;
            for(int i = 0;i < N;i++)
            {
                if(vis_g[i] == 0)
                {
                    num1[secret[i]]++;
                    num2[guess[i]]++;
                }
            }
            for(int i = 1;i < 10;i++)
            {
                second += min(num1[i],num2[i]);
            }
            printf("    (%d,%d)\n",first,second);
        }
    }
    return 0;
}
