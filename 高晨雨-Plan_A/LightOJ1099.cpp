//求最次路径，本题的权值为路径中各边权值之和，利用二维数组，保存最小值和次小值
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;

#define cler(arr, val)    memset(arr, val, sizeof(arr))
const int MAXN = 5010+1;
const int MAXM = 240000;
const int INF = 0x3f3f3f3f;
int dist[MAXN][2],head[MAXN],tol;
bool vis[MAXN][2];
struct node
{
    int u,v,val,next;
}edge[MAXM];
void addedge(int u,int v,int w)
{
    edge[tol].u=u,edge[tol].v=v,edge[tol].val=w,edge[tol].next=head[u];
    head[u]=tol++;
    edge[tol].u=v,edge[tol].v=u,edge[tol].val=w,edge[tol].next=head[v];
    head[v]=tol++;
}
void Dijistra(int n)
{
    for(int i=0;i<=n;i++)
        dist[i][0]=dist[i][1]=INF,vis[i][0]=vis[i][1]=false;
    dist[0][0]=0;
    while(true)
    {
        int v=-1,k;
        int minlen=INF;
        for(int u=0;u<n;u++)
        {
            for(int l=0;l<2;l++)
                if(!vis[u][l]&&(v==-1||dist[u][l]<minlen))
                {
                    minlen=dist[u][l];
                    k=l;
                    v=u;
                }
        }
        if(v==-1) break;
        vis[v][k]=true;
        for(int i=head[v];~i;i=edge[i].next)
        {
            int u=edge[i].v;//目标
            int cost=dist[v][k]+edge[i].val;
            if(cost<dist[u][0])
            {
                dist[u][1]=dist[u][0];
                dist[u][0]=cost;
            }
            else if(cost<dist[u][1]&&cost>dist[u][0])
            {
                dist[u][1]=cost;
            }
        }
    }
}
int main()
{
    int t,n,m,u,v,w,cas=1;
    cin>>t;
    while(t--)
    {
        cler(head,-1);
        tol=0;
        cin>>n>>m;
        int a=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            a=max(a,u);
            a=max(a,v);
            u--,v--;
            addedge(u,v,w);
        }
        Dijistra(a);
        printf("Case %d: %d\n",cas++,dist[n-1][1]);
    }
    return 0;
}
