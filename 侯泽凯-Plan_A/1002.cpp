#include<bits/stdc++.h>
using namespace std;

#define maxn 510
#define inf 0x3f3f3f3f

int tmap [maxn][maxn];
int dis [maxn];

void initmap()
{
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			if(i==j)
			{
				tmap[i][j] = 0;
			}
			else
			{
				tmap[i][j]=inf;
			}
		}
	}
}

void dijkstra(int n,int s)
{
	int i,j,k,minn;
	int vis[maxn];
	memset(vis,0,sizeof(vis));

	for(int i=0;i<n;i++)
	{
		dis[i]=tmap[s][i];
	}
	vis[s]=1;

	for(int i=1;i<=n-1;i++)
	{
		minn=inf;
		for(int j=0;j<n;j++)
		{
			if(vis[j]==0&&minn>dis[j])
			{
				minn=dis[j];
				k=j;
			}
		}

		if(minn==inf)
		{
			return;
		}

		vis[k]=1;

		for(int j=0;j<n;j++)
		{
			if(vis[j]==0)
			{
				dis[j]=min(dis[j],max(tmap[k][j],dis[k]));
			}
		}
	}

}

int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		initmap();

		int n,m;
		cin>>n>>m;

		while(m--)
		{
			int u,v,w;
			cin>>u>>v>>w;
			if(tmap[u][v]>w)
			{
				tmap[u][v]=w;
				tmap[v][u]=w;
			}
		}

		int ori;
		cin>>ori;
		dijkstra(n,ori);

		printf ("Case %d:\n",z);

		for(int i=0;i<n;i++)
		{
			if(dis[i]!=inf)
			{
				cout<<dis[i]<<endl;
			}
			else
			{
				cout<<"Impossible"<<endl;
			}
		}
	}
	return 0;
}
