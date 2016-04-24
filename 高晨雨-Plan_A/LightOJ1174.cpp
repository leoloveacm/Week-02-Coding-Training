//floyd算法裸题
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
#define Max 105
#define INF 0x3f3f3f3f

int dist[Max][Max];

void init(int n)
{
	int i,j,k;
	for(i=0;i<=n;i++)
		for(j=0;j<=n;j++)
		{
			if(i==j) dist[i][j]=0;
			else dist[i][j]=INF;
		}
}

void Floyd(int n)
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(dist[i][k]+dist[k][j]<dist[i][j])
				{
					dist[i][j]=dist[i][k]+dist[k][j];
				}
			}
}
int main()
{
	int T,N,R,u,v,s,d,l=1;
	cin>>T;
	while(T--)
	{
		cin>>N>>R;
		init(N);
		while(R--)
		{
			cin>>u>>v;
			dist[u][v]=dist[v][u]=1;
		}
		cin>>s>>d;
		Floyd(N);
		int ans=-1;
		for(int i=0;i<N;i++)
		{
			if(dist[s][i]==INF||dist[i][d]==INF) continue;
			ans=max(ans,dist[s][i]+dist[i][d]);
		}
		printf("Case %d: %d\n",l++,ans);
	}
	return 0;
}
