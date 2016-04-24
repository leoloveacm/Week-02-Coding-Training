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
/*//如果不是叶子节点，就一直加，到叶子节点就判断是否相等
#include<iostream>
using namespace std;

bool ok;//是否存在路径

bool tree_sum(int n,int sum)
{
    int v;
    char ch;

    cin>>ch;//吸收左括号

    if(cin>>v)//如果左括号后面是int型变量
    {
        n+=v;
		//这里非常巧妙，因为先判断第一个函数，这样就可以做到前序遍历一棵树
		//因为不用记录树的信息，所以边输入，边处理就可以直接得到结果~
        bool t= tree_sum(n,sum) | tree_sum(n,sum);

        if(ok==false&&t==false)//判断是否左右皆为为空子树
			ok=(n==sum);

        cin>>ch;//吸收左括号
        return true;//非空树
    }

    else//左括号后面跟右括号
    {
        cin.clear();//消除错误状态（右括号）

        cin>>ch;//吸收左括号
        return false;//为空树
    }

}
int main()
{
    int sum;
    while(cin>>sum)
    {
        ok=false;

        tree_sum(0,sum);

        cout<<(ok?"yes":"no")<<endl;
    }
    return 0;
}
*/
