//首先自首：这道题是看多题解才做的。不过保证是看懂后自己敲的。
//前序建树同时遍历并计算。
#include<bits/stdc++.h>
using namespace std;

bool ac;

bool tree(int n,int sum)
{
	int val;
	char bc;

	cin>>bc;
	if(cin>>val)
	{
		n+=val;

		bool treeson = tree(n,sum) | tree(n,sum) ;

		if(ac==false&&treeson==false)
		{
			ac=(n==sum);
		}

		cin>>bc;
		return true;
	}
	else
	{
		cin.clear();

		cin>>bc;
		return false;
	}
}

int main()
{
	int jug;
	while(cin>>jug)
	{
		ac=false;

		tree(0,jug);

		cout<<(ac?"yes":"no")<<endl;
	}
	return 0;
}
