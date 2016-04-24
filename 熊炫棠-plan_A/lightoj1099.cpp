//次短路用dijkstra还真要用二维数组，之前想得太简单，看着题解写的。。
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=5009;
const int M=100009;
int dis[N][3];
int con[N];
int n,m;
struct LT{
    int to,dis,nex;
} L[M<<1];
int F[N],cnt;
void add(int f,int t,int d){
    L[cnt].to=t;
    L[cnt].nex=F[f];
    L[cnt].dis=d;
    F[f]=cnt++;
}
void in(int k,int s){
    if(s<dis[k][0])
    dis[k][1]=dis[k][0],dis[k][0]=s;
    else if(s!=dis[k][0])
    dis[k][1]=s;
}
void dj(){
    memset(dis,INF,sizeof(dis));
    memset(con,0,sizeof(con));
    for(int i=F[1];i;i=L[i].nex){
        dis[L[i].to][0]=L[i].dis;
    }
    dis[1][0]=0;
    for(int k=-n;k<=n;k++){
        int minone=-1,mindis=INF;
        for(int i=1;i<=n;i++)
        if(con[i]<2&&dis[i][con[i]]<mindis){
            mindis=dis[i][con[i]];
            minone=i;
        }
        if(minone==-1) break;
        int c= con[minone];
        con[minone]++;
        if(con[n]==2) break;
        for(int i=F[minone];i;i=L[i].nex){
            int to= L[i].to;
            if(con[to]<2&&dis[to][1]>dis[minone][c]+L[i].dis){
                in(to,dis[minone][c]+L[i].dis);
            }
        }
    }
    printf("%d\n",dis[n][1]);
}
int main(){
    int cas,T=1;
    scanf("%d",&cas);
    while(cas--){
        scanf("%d%d",&n,&m);
        int a,b,c;
        memset(F,0,sizeof(F));cnt=1;
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);add(b,a,c);
        }
        printf("Case %d: ",T++);
        dj();
    }
    return 0;
}
