/*
这道题所给出的数字顺序是二叉树的中序遍历，所以可以用二叉树遍历做，参考了大神的代码；
int v,cin>>v;可以跳过空格和回车等无效输入。
还学习了 cin.clear() 等的用法
*/
#include <bits/stdc++.h>

using namespace std;

int sum,flag;

int dfs(int sum,int n){
   char ch;
   cin>>ch;
   int v;
   if(!(cin>>v)==0){
        n+=v;
        int left=dfs(sum,n),right=dfs(sum,n);
        if(left&&right&&!flag){
                if(sum==n) flag=1;
        }
        cin>>ch;
        return 0;
   }
  else {
        cin.clear();
        cin>>ch;
        return 1;
  }
}

int main()
{
    while(scanf("%d",&sum)!=EOF){
        flag=0;
        dfs(sum,0);
        if(flag) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
