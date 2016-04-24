/*
水题，注意输出格式。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=1000;

using namespace std;

int n,s,w,fl,icase,a[maxn+10],b[maxn+10],flag[maxn+10];

int main()
{
    while(scanf("%d",&n)!=EOF&&n){
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    fl=0;
    while(1){
        s=0,w=0,memset(flag,0,sizeof(flag));
        for(int i=1;i<=n;i++){
                scanf("%d",&b[i]);
        }
        if(b[1]==0) break;
        for(int i=1;i<=n;i++){
                if(b[i]==a[i]) s++,flag[i]=1;
                else {
                        for(int j=1;j<=n;j++){
                                if(b[i]==a[j]&&!flag[j]&&b[j]!=a[j]) {
                                                w++,flag[j]=1;
                                                break;
                                }
                        }
                }
        }
        if(!fl)
        {
        printf("Game %d:\n",++icase);
        fl++;
        }
        printf("    (%d,%d)\n",s,w);
    }
    }
    return 0;
}
