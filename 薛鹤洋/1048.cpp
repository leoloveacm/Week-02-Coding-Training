/*
最小化最大值，很明显二分结果。
要输出结果的话，我用的dfs搜，刚开始超时，搜出结果直接return回去，ac。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1000;

using namespace std;

int t,n,h,k,minn,sum,ans,a[maxn+10],b[maxn+10];

int C(int mid){
   if(mid<minn) return 0;
   int cnt=0,cur=0,su=0;
    while(cur<=n+1){
        while(cur<=n+1&&su+a[cur]<=mid) {
        su+=a[cur];cur++;
        }
        cnt++,su=0;
    }
   if(cnt>k+1) return 0;
   else return 1;
}

int dfs(int x,int y,int index){
   if(y==k+1&&index==n+2) {
        for(int i=0;i<k+1;i++) printf("%d\n",b[i]);
        return 1;
   } else {
      int s=0,i;
      for(i=index;i<=n+1;i++){
        if(s+a[i]<=x) s+=a[i];
        else break;
      }
      for(int j=i-1;j>=index;j--){
        b[y]=s;
        if(dfs(x,y+1,j+1)) return 1;
        s-=a[j];
      }
   }
   return 0;
}

void solve(){
  int lb=0,ub=sum+1;
  while(ub-lb>1){
        int mid=(lb+ub)/2;
        if(C(mid)) {
           ub=mid;
        } else lb=mid;
  }
  printf("Case %d: %d\n",h,ub);
  dfs(ub,0,1);
}

int main()
{
    scanf("%d",&t);
    for(h=1;h<=t;h++){
        memset(a,0,sizeof(a));
        minn=0,sum=0,ans=0;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n+1;i++) {
        scanf("%d",&a[i]);
        minn=max(a[i],minn);
        sum+=a[i];
        }
        if(k+1>=n+1) {printf("Case %d: %d\n",h,minn);
        for(int i=1;i<=n+1;i++) {
                printf("%d\n",a[i]);
        }
        continue;}
        solve();
      //printf("%d\n",C(6));
    }
    return 0;
}
