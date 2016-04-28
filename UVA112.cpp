#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
const int MAXN=10010;
int tree[MAXN*4];
int main(){
	int des;
	int left,right,level,cnt,maxl;
	char c;
	while(scanf("%d",&des)!=EOF){
        memset(tree,0,sizeof(tree));
        left=0;
        right=0;
        level=1;
        cnt=0;
        maxl=0;
        while(1){
            scanf("%c",&c);
            while(c=='\n'||c==' ')
                scanf("%c",&c);
            if(c=='('){
                right++;
                int d;
                if(scanf("%d",&d)){
                    tree[level]=d+tree[level/2];
                    level=level*2+cnt;
                    maxl=max(maxl,level);
                }
            }
            else if(c==')'){
                left++;
                cnt=level%2;
                level/=2;
                if(cnt==0) cnt=1;
            }
            else ;
            if(left==right) break;
        }

	}
	return 0;
}
