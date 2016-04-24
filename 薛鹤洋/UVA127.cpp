/*
模拟题，可以用vetor+stack模拟。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=10;

using namespace std;

struct card{
  char s,r;
};

char a[maxn+1];

vector<stack<card> > pile;

int judge(card a,card b){
   if(a.s==b.s||a.r==b.r) return 1;
   return 0;
}

int main()
{
    while(1){
        pile.clear();
        int flag=1;
        for(int i=1;i<=52;i++){
        scanf("%s",a);
        if(a[0]=='#') {flag=0;break;}
        stack<card> b;
        card c;
        c.r=a[0],c.s=a[1];
        b.push(c);
        pile.push_back(b);
        }
        if(!flag) break;
        while(flag){
        flag=0;
        for(int i=0;i<pile.size();++i) if(pile[i].empty()) pile.erase(pile.begin()+i);
        for(int i=0;i<pile.size();++i){
                if(i-3>=0){
                if(judge(pile[i].top(),pile[i-3].top()))
                    {
                        pile[i-3].push(pile[i].top());
                        pile[i].pop();
                        flag=1;
                        break;
                    }
                }
                    if(i-1>=0){
                    if(judge(pile[i].top(),pile[i-1].top()))
                    {
                        pile[i-1].push(pile[i].top());
                        pile[i].pop();
                        flag=1;
                        break;
                    }
                    }
        }
       // if(!flag) break;
    }
    if(pile.size()>1){ printf("%d piles remaining:",pile.size());
    for(int i=0;i<pile.size();++i){
        printf(" %d",pile[i].size());
    }
    printf("\n");
    }
    else {
        printf("%d pile remaining:",pile.size());
        for(int i=0;i<pile.size();++i){
        printf(" %d",pile[i].size());
    }
    printf("\n");
    }
    }
    return 0;
}
