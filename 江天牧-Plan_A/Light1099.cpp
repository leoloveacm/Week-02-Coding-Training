//求次短路，用dijistra，次短路，只需让每个节点维护两个值，并且允许一个节点经过两次，就可求得次短路
#include <iostream>
#include<cstdio>
#include<cstring>

const int MAXN = 5001 +10;
const int INF = 0x3f3f3f3f;
struct BIAN
{
    int son,to;
    int value;
};
struct BIAN bian[100005*2];
int head[MAXN];
bool vis[MAXN][2];
int dis[MAXN][2];//0最1次
using namespace std;
int cnt;
int N;
void ADDbian(int u, int v, int value)
{
    bian[cnt].son = v;
    bian[cnt].to = head[u];
    bian[cnt].value = value;
    head[u] = cnt++;
    bian[cnt].son = u;
    bian[cnt].to = head[v];
    bian[cnt].value = value;
    head[v] = cnt++;
}

int Dijistra()
{
    for(int i = 1; i<= N;i++)
    {
        vis[i][0] = 0;
        vis[i][1] = 0;
        dis[i][0] = INF;
        dis[i][1] = INF;
    }
    //vis[1] = 1;
    //dis[1][0] = 0;
    dis[1][1] = 0;
    while(true)
    {
        int u = -1;
        int k;
        int tempmin = INF;
        for(int i = 1;i <= N;i++)
        {
            for(int l = 0;l<=1;l++){
                if(!vis[i][l] && dis[i][l]<tempmin)
                {
                    u = i;
                    tempmin = dis[i][0];
                    k = l;
                }
            }
        }
        if(u == -1)
        {
            break;
        }
        vis[u][k] = true;
        for(int i = head[u]; i!= -1;i = bian[i].to)
        {
            int temp = bian[i].value + dis[u][k];
            int v = bian[i].son;
            if(temp < dis[v][0])
            {
                dis[v][1] = dis[v][0];
                dis[v][0] = temp;
            }
            else if(temp <dis[v][1] && temp > dis[v][0])
            {
                dis[v][1] = temp;
            }
        }
    }
    return dis[N][1];
}

int main()
{
    int T;
    cin >> T;
    int Case = 1;
    while(T--)
    {
        int R;
        scanf("%d%d",&N,&R);
        cnt = 0;
        memset(head,-1,sizeof(head));
        for(int i = 1; i <= R;i++)
        {
            int u,v,value;
            scanf("%d%d%d",&u,&v,&value);
            ADDbian(u,v,value);
        }
        printf("Case %d: ",Case++);
        printf("%d\n",Dijistra());
    }
    return 0;
}
