//基于优先队列的迪杰科斯彻算法，因为是无向图，所以一条路可以走多次
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define INF 0xfffffff
using namespace std;

struct Edge{
    int to;//从哪条边去to这个点
    int cost;
};

int n,r;

vector<Edge> edge[5005];//邻接前向星,edge数组下标表示from

typedef pair<int,int> P;//first是最短距离，second是顶点编号

int dis1[5005];//k点最短距离
int dis2[5005];//k点次短距离

int solve()
{
    priority_queue<P,vector<P>,greater<P> > q;//小的优先级高，先排first，后排second
    for(int i = 0; i <= n; i++)
	{
        dis1[i] = INF;
        dis2[i] = INF;
    }
    dis1[1] = 0;//起点

    q.push(P(0,1));//1点入队

    while(!q.empty())//每次从当前求出的最短线路出发
	{
        P p;
        p = q.top();//始终去找最短的那个点
        q.pop();

		int d = p.first;//1为位置到队首的最短距离
        int v = p.second;//队首位置编号

        if(d > dis2[v])//这条来路比v点的次短路长
		{
			continue;
		}
		//d <= dis2[v]时
        for(int i = 0; i < edge[v].size(); i++)//在v点处，去找下一条路
		{
            Edge e = edge[v][i];//拿出来，防止无意中修改原图
            int d2 = d + e.cost;//去下一个点的距离
            if(dis1[e.to] > d2)//比最短路短
			{
                swap(dis1[e.to],d2);
                q.push( P(dis1[e.to],e.to) );
            }
            if(dis2[e.to] > d2 && dis1[e.to] < d2)//大于最短路，小于次短路
            {
                dis2[e.to] = d2;
                q.push( P(dis2[e.to],e.to) );
            }
        }
    }
    return dis2[n];//终点已知
}

int main()
{
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
	{
        scanf("%d%d",&n,&r);

        for(int i = 0; i <= n; i++)//初始化（易漏）
        {
        	edge[i].clear();
        }

        int u,v,cost;
        Edge tmp;

        for(int i = 0; i < r; i++)
		{
            scanf("%d%d%d",&u,&v,&cost);
				tmp.to = v;
				tmp.cost = cost;
            edge[u].push_back(tmp);//无向图存两边
				tmp.to = u;
            edge[v].push_back(tmp);
        }
        solve();
        printf("Case %d: %d\n",z,solve());
    }
    return 0;
}

