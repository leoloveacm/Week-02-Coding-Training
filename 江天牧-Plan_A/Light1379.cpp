//没有a掉的题，求在某一费用一下，能经过的最大边，我用dfs搜索（考虑可能有环）每个点可以经过两次（多次就没有意义了），但是时间太长，网上说要用spfa解，正在学。。。
#include <iostream>
#include<cstdio>
#include<cstring>

using namespace std;
int N,M,s,t,p;
const int maxn = 10005;
const int maxm = 50005;
const int INF =0x3f3f3f3f;
int cnt;
int head[maxn];
struct BIAN
{
    int son,to,value;
}bian[maxm];
void add(int u,int v,int value)
{
    bian[cnt].son = v;
    bian[cnt].to = head[u];
    bian[cnt].value = value;
    head[u] = cnt++;
}
int maxroad = -0x3f3f3f3f;
int vis[maxn];
void dfs(int u,int sum,int rool)
{
    if(sum > p)
        return;
    if(u == t)
    {
        if(rool > maxroad)
            maxroad = rool;
        return;
    }
    for(int i = head[u]; i!= -1;i = bian[i].to)
    {
        int v = bian[i].son;
        if(vis[v]<2){
            vis[v]++;
            dfs(v,sum + bian[i].value,(rool>bian[i].value)?rool:bian[i].value);
            vis[v]--;
        }
    }
    return;
}

int main()
{
    int T;
    cin >> T;
    int Case  = 1;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        memset(head,-1,sizeof(head));
        scanf("%d%d%d%d%d",&N,&M,&s,&t,&p);
        cnt = 0;
        while(M--)
        {
            int u,v,value;
            scanf("%d%d%d",&u,&v,&value);
            add(u,v,value);
        }
        maxroad = -0x3f3f3f3f;
        printf("Case %d: ",Case++);
        vis[s] = 1;
        dfs(s,0,-INF);
        if(maxroad != -INF)
        {
            printf("%d\n",maxroad);
        }
        else
        {
            printf("-1\n");
        }
    }

    return 0;
}
