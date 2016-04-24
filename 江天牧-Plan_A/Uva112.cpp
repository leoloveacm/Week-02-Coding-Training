//求一棵树从跟节点到叶子的是否存在等于给出值的路径，一开始怎么都写不清楚，尤其是scanf的用法不知
//道如何处理不确定的回车和空格，参考了网上大神的做法后面感觉收获很大，尤其是scanf的读入特性和返回值，一开
//始想用节点的结构体写的，但是好像利用递归的特点可以巧妙的回避掉。
#include<cstdio>

int sum(int n)
{
    int m,ret;
    if(scanf(" (%d",&m)) //返回0说明遇到叶子
    {
        ret=sum(n-m)+sum(n-m);//在叶子节点返回2说明路径可用
    }
    else
    {
        if(n==0) //在叶子节点n==0说明刚好减完得到便返回1
            ret=1;
        else
            ret=0;
    }
    scanf(" )");
    return ret;

}

int main() {

    int n;
    while (scanf("%d", &n) != EOF)
    {
        printf("%s\n", sum(n) >= 2 ? "yes" : "no");
    }
    return 0;
}
