//floyd模板题

//注意——inf太大的时候d[i][k]+d[k][j]会溢出，inf应设置为仅比最短路上限大一点
//或者：坚持不允许inf和其他值相加（修改见代码）

#include<bits/stdc++.h>
using namespace std;

#define inf 9999999
#define maxn 110//2333

int mapt[maxn][maxn];

void init()
{
	for(int i=0;i<maxn;i++)
	{
		for(int j=0;j<maxn;j++)
		{
			if(i==j)
				mapt[i][j]=0;
			else
				mapt[i][j]=inf;
		}
	}
}

void floyd(int n)
{
	for(int k = 0; k < n ;k++)
	{
		for(int i = 0; i < n; i++)
		{
			 for(int j = 0; j < n; j++)
			 {
			 	mapt[i][j] = min(mapt[i][j], mapt[i][k]+mapt[k][j]);
			 }
		}
	}
}
/*version two
void floyd(int n)
{
	for(int k = 0; k < n ;k++)
	{
		for(int i = 0; i < n; i++)
		{
			 for(int j = 0; j < n; j++)
			 {
				if(d[i][j]<inf&&d[k][j]<inf)
					mapt[i][j] = min(mapt[i][j], mapt[i][k]+mapt[k][j]);
			 }
		}
	}
}
*/

int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		int n,m,s,e,u,v;
		init();
		cin>>n>>m;
		while(m--)
		{
			cin>>u>>v;
			mapt[u][v]=mapt[v][u]=1;
		}
		cin>>s>>e;
		floyd(n);
		int ans=-1;
		for(int i=0;i<n;i++)
		{
			if(mapt[s][i] == inf || mapt[i][e] == inf)
				continue;
            ans = max(ans,mapt[s][i]+mapt[i][e]);
		}
		cout<<"Case "<<z<<": "<<ans<<endl;
	}
	return 0;
}
