#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int a[1010],b[1010];
int aux[15],bux[15],dux[15];
int main(){
	int n,nc(1);
	while(scanf("%d",&n)!=EOF){
        if(n==0) break;
        memset(a,0,sizeof(a));
        printf("Game %d:\n",nc++);
        memset(aux,0,sizeof(aux));
        memset(dux,0,sizeof(dux));
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            aux[a[i]]++;
            dux[a[i]]++;
        }
        while(1){
            memset(bux,0,sizeof(bux));
            for(int i=0;i<10;i++){
                aux[i]=dux[i];
            }
            for(int i=0;i<n;i++)
            {
                scanf("%d",&b[i]);
                bux[b[i]]++;
            }
            if(bux[0]==n) break;
            int ans1(0),ans2(0);
            for(int i=0;i<n;i++){
                if(a[i]==b[i])
                {
                    ans1++;
                    aux[a[i]]--;
                    bux[b[i]]--;
                }
            }
            for(int i=0;i<10;i++){
                ans2+=min(aux[i],bux[i]);
                /*cout<<"a: "<<aux[i]<<" || b: "<<bux[i]<<" duan "<<endl;
                cout<<ans2<<endl;*/
            }
            printf("    (%d,%d)\n",ans1,ans2);
        }
	}
	return 0;
}
