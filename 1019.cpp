#include<bits/stdc++.h>
using namespace std;

#define maxn 105
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
			if(vis[j]==0&&dis[j]>tmap[k][j]+minn)
			{
				dis[j]=tmap[k][j]+minn;
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
			if(tmap[u-1][v-1]>w)
			{
				tmap[u-1][v-1]=w;
				tmap[v-1][u-1]=w;
			}
		}

		dijkstra(n,0);

		if(dis[n-1]!=inf)
		{
			printf ("Case %d: ",z);
			cout<<dis[n-1]<<endl;
		}
		else
		{
			printf ("Case %d: ",z);
			cout<<"Impossible"<<endl;
		}
	}
	return 0;
}
