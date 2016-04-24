//通过多个栈模拟机器手臂操作，注意两个木块在同一列时不操作
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
int main()
{
	int n,a,b;
	stack<int> blocks[30];
	char first[10],second[10];
	int check[30]={0};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		blocks[i].push(i);
		check[i]=i;
	}
	while(scanf("%s",first))
	{
		if(first[0]=='q') break;
		scanf("%d%s%d",&a,second,&b);
		if(check[a]==check[b]) continue;
		if(first[0]=='m'&&second[1]=='n')
		{
			int A=check[a],B=check[b];
			while(blocks[A].top()!=a)
			{
				check[blocks[A].top()]=blocks[A].top();
				blocks[blocks[A].top()].push(blocks[A].top());
				blocks[A].pop();
			}
			while(blocks[B].top()!=b)
			{
				check[blocks[B].top()]=blocks[B].top();
				blocks[blocks[B].top()].push(blocks[B].top());
				blocks[B].pop();
			}
			check[blocks[A].top()]=check[blocks[B].top()];
			blocks[B].push(blocks[A].top());
			blocks[A].pop();
		}
		if(first[0]=='m'&&second[1]=='v')
		{
			int A=check[a],B=check[b];
			while(blocks[A].top()!=a)
			{
				check[blocks[A].top()]=blocks[A].top();
				blocks[blocks[A].top()].push(blocks[A].top());
				blocks[A].pop();
			}
			check[blocks[A].top()]=check[blocks[B].top()];
			blocks[B].push(blocks[A].top());
			blocks[A].pop();
		}
		if(first[0]=='p'&&second[1]=='v')
		{
			int i=0,p[30]={0};
			int A=check[a],B=check[b];
			for(i=0;blocks[A].top()!=a;i++)
			{
				p[i]=blocks[A].top();
				blocks[A].pop();
			}
			p[i]=blocks[A].top();
				blocks[A].pop();
			for(int j=i;j>=0;j--)
			{
				check[p[j]]=check[blocks[B].top()];
				blocks[B].push(p[j]);
			}
		}
		if(first[0]=='p'&&second[1]=='n')
		{
			int A=check[a],B=check[b];
			while(blocks[B].top()!=b)
			{
				check[blocks[B].top()]=blocks[B].top();
				blocks[blocks[B].top()].push(blocks[B].top());
				blocks[B].pop();
			}
			int i=0,p[30]={0};
			for(i=0;blocks[A].top()!=a;i++)
			{
				p[i]=blocks[A].top();
				blocks[A].pop();
			}
			p[i]=blocks[A].top();
				blocks[A].pop();
			for(int j=i;j>=0;j--)
			{
				check[p[j]]=check[blocks[B].top()];
				blocks[B].push(p[j]);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d:",i);
		int siz=blocks[i].size();
		int k[30]={0};
		if(siz==0) printf("\n");
		else{
			for(int j=0;j<siz;j++)
			{
				k[j]=blocks[i].top();
				blocks[i].pop();
			}
			for(siz=siz-1;siz>=0;siz--)
			{
				printf(" %d",k[siz]);
			}
			printf("\n");
		}
	}
	return 0;
}
