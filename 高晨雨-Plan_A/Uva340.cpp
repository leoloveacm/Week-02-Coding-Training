//输出完全匹配的个数以及数字猜对位置不对的个数，分别统计答案与猜测中每个数字出现的个数，暴力
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int N;
int num[13],check[13];
int s[1005],a[1005];
int main()
{
	int T,cnt=0,ans,n;
    while(scanf("%d",&T)!=EOF)
	{
		if(T==0) break;
		cnt++;
		memset(num,0,sizeof(num));
		for(int i=1;i<=T;i++)
		{
			cin>>s[i];
			num[s[i]]++;
		}
		printf("Game %d:\n",cnt);
		while(1)
		{
			memset(check,0,sizeof(check));
			ans=0;
			for(int i=1;i<=T;i++)
			{
				cin>>a[i];
				check[a[i]]++;
				if(a[i]==s[i]) ans++;
			}
			if(a[1]==0) break;
			n=0;
			for(int i=1;i<=9;i++)
			{
				if(num[i]>check[i])
				   n+=(check[i]);
				else n+=num[i];
			}
			printf("    (%d,%d)\n",ans,n-ans);
		}
	}
	return 0;
}
