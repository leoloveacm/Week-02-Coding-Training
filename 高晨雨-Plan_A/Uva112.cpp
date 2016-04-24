//实现二叉树的先序遍历，对比是否存在需要的答案，递归
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

bool check;
bool tree(int n,int sum)
{
	int num;
	char ch;
	cin>>ch;
	if(cin>>num)
	{
		n+=num;
		bool t=tree(n,sum)|tree(n,sum);
		if(check==false&&t==false)
		   check=(n==sum);
		cin>>ch;
		return true;
	}
	else
	{
		cin.clear();
		cin>>ch;
		return false;
	}
}
int main()
{
	int s;
	while(cin>>s)
	{
		check=false;
		tree(0,s);
		cout<<(check?"yes":"no")<<endl;
	}
	return 0;
}