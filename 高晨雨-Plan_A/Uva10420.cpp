//输入国家和名字按字典数输出国家中不同名字的个数，map有对键值自动排序的功能
#include<stdio.h>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	map<string,int> Gio;//键值设为国家名字，实值是出现次数
	map<string,int> ::iterator it;
	char N[80];
	char C[80];
	int T;
	cin>>T;
	while(T--)
	{
		cin>>C;
		gets(N);
		Gio[C]++;
	}
	for(it=Gio.begin();it!=Gio.end();it++)
		cout<<it->first<<" "<<it->second<<endl;//利用迭代器输出键值和实值
	return 0;
}