//数据很小，直接暴力
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<list>
#include<cstring>
using namespace std;
int main(){
    int i,a[1005],b[1005],c[1005],o=0,n,ans1,ans2;
    while(scanf("%d",&n)!=EOF&&n!=0){
        o++;
        printf("Game %d:\n",o);
        for(i=1;i<=n;i++)   scanf("%d",&c[i]);
        while(i){
            ans1=0,ans2=0;
            for(i=1;i<=n;i++){
                scanf("%d",&b[i]);
                a[i]=c[i];
                if(b[i]==a[i]) ans1++;
                if(b[i]==0) ans2++;
            }
            if(ans2==n) break;
            ans2=0;
            for(i=1;i<=n;i++)
            for(int j=1;j<=n;j++){
                if(a[i]==b[j]&&a[i]!=-999){
                    ans2++;
                    a[i]=b[j]=-999;
                }
            }
            printf("    (%d,%d)\n",ans1,ans2-ans1);
        }
    }
    return 0;
}
