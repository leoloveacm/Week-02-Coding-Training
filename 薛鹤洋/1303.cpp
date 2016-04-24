/*
模拟题，用list模拟人的队伍，用deque模拟座位。
用deque模拟队伍会超时。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int t,n,m,cou,ans,status,seat[maxn+10];

struct p{
  int num,cnt,flag[maxn+10];
}a[maxn+10];

list<int> q;

deque<int> s,r;

int judge(int n,int m){
    for(int i=1;i<=n;i++){
        if(a[i].cnt!=m) return 1;
   }
   if(status!=0) return 1;
   return 0;

}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        scanf("%d%d",&n,&m);
        q.clear(),r.clear(),s.clear(),ans=0,status=0;
        for(int i=1;i<=n;i++){
                a[i].cnt=0;
                for(int j=1;j<=m;j++) a[i].flag[j]=0;
                a[i].num=i;
                q.push_back(i);
        }
        for(int i=1;i<=m;i++) r.push_back(i);
        while(judge(n,m)){
           int fl=0;
           ans+=5;
           int s=r.front();
           r.pop_front();
           r.push_back(s);
          // printf("%d\n",s);
           if(!q.empty()){
           list<int>::iterator it=q.begin();
           for(;it!=q.end();++it){
                if(a[(*it)].flag[s]==0){
                        a[(*it)].flag[s]=1;
                        a[(*it)].cnt++;
                if(seat[s]&&a[seat[s]].cnt!=m){
                        q.push_back(seat[s]);
                }
                seat[s]=(*it);
                status|=(1<<s);
                q.erase(it);
                fl=1;
                break;
                }
           }
           }
           if(fl==0){
                     if(seat[s]&&a[seat[s]].cnt!=m){
                        q.push_back(seat[s]);
                }
                seat[s]=0;
                status&=(~(1<<s));
           }
       //for(int i=1;i<=n;i++){
       // printf("%d",a[i].cnt);
       // }
       // printf("\n");
        }
        printf("Case %d: %d\n",h,ans);
}
    return 0;
}
