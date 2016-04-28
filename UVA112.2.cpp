#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int des,l,r,level,sum;
int tree[4010];
char ch[4];
int main(){
    char c;
	while(scanf("%d",&des)!=EOF){
        memset(tree,0,sizeof(tree));
        memset(ch,' ',sizeof(ch));
        level=0;
        sum=0;
        l=r=0;
        int fu=1;
        bool flag=0;
        bool biaoji=1;
        bool re;
        while(l!=r||biaoji){
            scanf("%c",&c);
            if((c>='0'&&c<='9')||c=='('||c==')'||c=='-'){
                if((c>='0'&&c<='9')||c=='-'){
                    if(c>='0'&&c<='9')
                        tree[level]=10*tree[level]+c-'0';
                    else fu=-1;
                    re=1;
                }
                else if(re){
                    tree[level]*=fu;
                    sum+=tree[level];
                    re=0;
                    level++;
                    fu=1;
                }
                else ;
                ch[3]=ch[2];
                ch[2]=ch[1];
                ch[1]=ch[0];
                ch[0]=c;
                if(ch[3]=='('&&ch[2]==')'&&ch[1]=='('&&ch[0]==')'){
                    if(sum==des) flag=1;
                    memset(ch,' ',sizeof(ch));
                }
                else if(ch[1]!='('&&ch[0]==')'){
                    sum-=tree[level-1];
                    tree[--level]=0;
                }
                if(c=='(')
                    l++;
                else if(c==')')
                    r++;
                if(l!=r) biaoji=0;
            }
        }
        if(flag) puts("yes");
        else puts("no");
	}
	return 0;
}
