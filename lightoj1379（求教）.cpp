#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int to;//从哪条边去to这个点
    int cost;
};

vector<Edge> edge[10005];
int dis;
int maxneed;

void solve(int s,int t)
{
	for(int i=0;i<edge[s].size;i++)
	{

	}
}

int main()
{
	int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
	{
		int n,m,s,t,p;
        scanf("%d%d%d%d%d",&n,&m,&s,&t,&p);

        for(int i = 0; i <= n; i++)
        {
        	edge[i].clear();
        }
        maxneed=-1;

        int u,v,cost;
        edge tmp;

        for(int i = 0; i < m; i++)
		{
            scanf("%d%d%d",&u,&v,&cost);
				tmp.to = v;
				tmp.cost = cost;
			//考虑重边************************************************** wa
            edge[u].push_back(tmp);
        }

        solve(s,t);

        printf("Case %d: %d\n",z,maxneed);
    }
	return 0;
}
/*
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
using namespace std;

struct edge
{
	int to, w;
	edge() {}
	edge(int a, int b) : to(a), w(b) {}
	bool operator <(const edge &o) const
	{
		return w > o.w;
	}
};

const int inf = 1000001 + 100;

vector<int> dijkstra(vector<vector<edge> > &g, int s)
{
	vector<int> d(g.size(), inf);
	d[s] = 0;
	priority_queue<edge> q;
	q.push(edge(s, 0));
	while (!q.empty())
	{
		int cur  = q.top().to;
		int dist = q.top().w;
		q.pop();

		if (dist > d[cur]) continue;
		for (int i = 0; i < g[cur].size(); ++i)
		{
			int to = g[cur][i].to;
			int w_extra =  g[cur][i].w;
			if (dist + w_extra < d[to])
			{
				d[to] = dist + w_extra;
				q.push(edge(to, d[to]));
			}
		}
	}
  return d;
}

void solve()
{
	int n, m, s, t, p;
	cin >> n >> m >> s >> t >> p;
	vector<vector<edge> > g1(n), g2(n);
	int u, v, w;
	for (int i = 0; i < m; ++i)
	{
		cin >> u >> v >> w;
		u--;v--;
		g1[u].push_back(edge(v, w));
		g2[v].push_back(edge(u, w));
	}
	s--; t--;
	vector<int> ds = dijkstra(g1, s);
	vector<int> dt = dijkstra(g2, t);
	int best = -1;
	for (int i = 0; i < g1.size(); ++i)
	{
		for (int j = 0; j < g1[i].size(); ++j)
		{
			u = i, v = g1[i][j].to, w = g1[i][j].w;
			if (ds[u] + w + dt[v] <= p)
			{
				best = max(best, w);
			}
		}
	}
	printf("%d\n", best);
}

int main()
{
  int tc; cin >> tc;
  for (int i = 0; i < tc; ++i)
	{
		printf("Case %d: ", i + 1);
		solve();
	}
  return 0;
}
*/
