//给出首尾两点，同时有多个人出发遍历整个图的最短时间，只需求出从首末两点到任意点的最短距离之和就是最短时间
#include <iostream>
#include<cstdio>
#include<cstring>
#include<queue>


using namespace std;
const int maxn = 105;
int N;
struct BIAN
{
    int son,to;
}bian[maxn*maxn];
int cnt;
int head[maxn];
void addBIAN(int u,int v)
{
    bian[cnt].son = v;
    bian[cnt].to = head[u];
    head[u] = cnt++;
    bian[cnt].son = u;
    bian[cnt].to = head[v];
    head[v] = cnt++;
}
int dis1[maxn];
void bfs1(int num1)
{
    queue<int> q;
    q.push(num1);
    dis1[num1] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u];i !=-1; i = bian[i].to)
        {
            int v = bian[i].son;
            if(dis1[v] == -1)
            {
                dis1[v] = dis1[u] + 1;
                q.push(v);
            }
        }
    }

}
int dis2[maxn];
void bfs2(int num)
{
    queue<int> q;
    q.push(num);
    dis2[num] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u];i !=-1; i = bian[i].to)
        {
            int v = bian[i].son;
            if(dis2[v] == -1)
            {

                dis2[v] = dis2[u] + 1;
                q.push(v);
                //cout << u<<" "<<v<<dis2[v]<<endl;
            }
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
        int R;
        memset(head,-1,sizeof(head));
        memset(dis1,-1,sizeof(dis1));
        memset(dis2,-1,sizeof(dis2));
        scanf("%d%d",&N,&R);
        cnt = 0;
        while(R--)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            addBIAN(u,v);
        }
        int num1,num2;
        scanf("%d%d",&num1,&num2);
        bfs1(num1);
        bfs2(num2);
        int maxnum = 0;
        for(int i = 0; i<N;i++)
        {
            if(dis1[i] + dis2[i] > maxnum)
                maxnum = dis1[i] + dis2[i];
        }
        printf("Case %d: %d\n",Case++,maxnum);
    }
    return 0;
}
