#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>
#include <queue>
#include <list>
using namespace std;
deque<int>dq;
deque<int>::iterator it;
const int inf=0xfffffff;
bool vis[22][22];
int mx[22];
int main(){
	int T;
	int n,m,nc(1);
	scanf("%d",&T);
	while(T--){
        scanf("%d%d",&n,&m);
        int ans=0,k=0,tmp;
        bool flag;
        dq.clear();
        memset(mx,inf,sizeof(mx));
        memset(vis,false,sizeof(vis));
        for(int i=0;i<n;i++) dq.push_back(i);
        while(1){
            ans++;
            flag=1;
            if(mx[k]>=0){
                dq.push_back(mx[k]);
                mx[k]=-1;
            }
            for(it=dq.begin();it!=dq.end();++it){
                tmp=(*it);
                if(!vis[tmp][k]){
                    mx[k]=tmp;
                    vis[tmp][k]=1;
                    dq.erase(it);
                    break;
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(!vis[i][j])
                    {
                        flag=0;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) break;
            k=(k+1)%m;
        }
        ans+=m;
        printf("Case %d: %d\n", nc++, ans*5);//先统计次数
	}
	return 0;
}
