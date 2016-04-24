//求其他所有城市到某一城市的（最大边的最小值），用Dijistra算法，把距离加边改成距离和边的最大值即可
#include <iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
struct BIAN
{
    int son,to;
    int value;
};

struct BIAN bian[16001*2];
const int INF = 0x3f3f3f3f;
const int maxn = 501;
using namespace std;
int n;
int dis[maxn];
int head[maxn];
int cnt;
bool vis[maxn];
void buid(int u,int v,int value)
{
    bian[cnt].value = value;
    bian[cnt].son = v;
    bian[cnt].to = head[u];
    head[u] = cnt;
    cnt++;
    bian[cnt].value = value;
    bian[cnt].son = u;
    bian[cnt].to = head[v];
    head[v] = cnt;
    cnt++;
}
int city;

void Djkstra(void)
{
    fill(dis, dis + n, INF);
    memset(vis,0,sizeof(vis));
    for(int i = head[city]; i != -1; i = bian[i].to)
    {
        dis[bian[i].son] = min(bian[i].value,dis[bian[i].son]);
    }
    dis[city] = 0;
    vis[city] = true;
    while(true)
    {
        int u = -1;
        int tempmin = INF;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i] && dis[i] < tempmin)
            {
                u = i;
                tempmin = dis[i];
            }
        }
        if(u == -1)
        {
            break;
        }
        vis[u] = true;
        for(int i = head[u]; i!= -1;i = bian[i].to)
        {
            dis[bian[i].son] = min(dis[bian[i].son],max(dis[u],bian[i].value));
        }
    }

}


int main()
{
    int T;
    cin >> T;
    int Case = 1;
    while(T--)
    {
        int m;
        scanf("%d%d",&n,&m);
        cnt = 0;
        memset(head,-1,sizeof(head));
        //memset(vis,-1,sizeof(vis));
        for(int i = 0;i < m;i++)
        {
            int u,v,value;
            scanf("%d%d%d",&u,&v,&value);
            buid(u,v,value);
        }

        scanf("%d",&city);
        Djkstra();
        printf("Case %d:\n",Case++);
        for(int i=0;i<n;i++)
        {
            if(dis[i] == INF)
            {
                printf("Impossible\n");
            }
            else
            {
                printf("%d\n",dis[i]);
            }
        }

    }
    return 0;
}
