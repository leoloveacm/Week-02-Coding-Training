//求s到其他n-1个点最短路径，本题权值为路径中各边权值之和
#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

#define maxn 510
#define INF 0x3f3f3f3f
int map[maxn][maxn], dist[maxn];//dis表示i到s的最短距离
void init ()//初始化地图
{
    int i, j;
    for (i=0; i<maxn; i++)
        for (j=0; j<maxn; j++)
            if (i==j)
                map[i][j] = 0;
            else
                map[i][j] = INF;
}
void dijkstra (int n, int s)//n个点，s为源点
{
    int i, j, vis[maxn],mini,k;
    memset (vis, 0, sizeof(vis));

    for (i=1; i<=n; i++)//初始化
        dist[i] = map[s][i];
    vis[s] = 1;

    for (i=0; i<=n-1; i++)//循环n-1次，求s到其他n-1个点最短路径
    {
        mini=INF;
        for (j=1; j<=n; j++)//在VB中的点取s 到其距离最小的k
            if (!vis[j] && mini > dist[j])
            {
                mini = dist[j];
                k = j;
            }
            if (mini == INF)
                return ;
        vis[k] = 1;
        for (j=1; j<=n; j++)
            if (!vis[j])
            {
                if(map[k][j]+dist[k]<dist[j])
					 dist[j]=map[k][j]+dist[k];
            }
    }
}
int main ()
{
    int T, n, m, l = 1;
    scanf ("%d", &T);
    while (T --)
    {
        init ();
        scanf ("%d%d", &n, &m);
        while (m --)
        {
            int u, v, w;
            scanf ("%d%d%d", &u, &v, &w);
            if (map[u][v] > w)//有重边，选最优
            map[u][v] = map[v][u] = w;
        }
        int t;
        //scanf ("%d", &t);
        dijkstra (n, 1);
        printf ("Case %d: ", l ++);
        //for (int i=0; i<n; i++)
            if (dist[n] != INF)
                printf ("%d\n", dist[n]);
            else
                printf ("Impossible\n");
    }
    return 0;
}
