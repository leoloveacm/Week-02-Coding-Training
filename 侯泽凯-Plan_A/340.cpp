//注意需要多次初始化，不然绝对wa。。。
#include<bits/stdc++.h>
using namespace std;

int ori[1005];
int gus[1005];
int cnt[10];
int opcnt[10];
int temp[10];

int main()
{
	int t;
	int z=1;
	while(cin>>t,t)
	{

		memset(cnt,0,sizeof(cnt));
		for(int i=0;i<t;i++)
		{
			cin>>ori[i];
			cnt[ori[i]]++;
		}

		printf("Game %d:\n",z);
		z++;

		while(1)
		{
			int sum=0;
			int a=0,b=0;

			for(int i=0;i<=9;i++)
			{
				temp[i]=cnt[i];
			}

			memset(opcnt,0,sizeof(opcnt));
			for(int i=0;i<t;i++)
			{
				cin>>gus[i];

				opcnt[gus[i]]++;

				sum+=gus[i];

				if(gus[i]==ori[i])
				{
					temp[gus[i]]--;
					opcnt[gus[i]]--;
					a++;
				}
			}

			if(sum==0)break;

			for(int i=0;i<t;i++)
			{
				if(temp[gus[i]]>0&&opcnt[gus[i]]>0)
				{
					temp[gus[i]]--;
					opcnt[gus[i]]--;
					b++;
				}
			}
			printf("    (%d,%d)\n",a,b);
		}
	}
	return 0;
}
