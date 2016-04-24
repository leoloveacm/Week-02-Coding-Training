//稍微简单一点的题，注意vector和stack的用法
#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
using namespace std;
struct edge{
    char s,r;
};
bool pan(edge a,edge b){
    if(a.s==b.s||a.r==b.r)
        return true;
    return false;
}
edge pai;
char kong;
int nu;
int main(){
    vector<stack<edge> > duis;
    bool flag=0;
    while(scanf("%c%c%c",&pai.s,&pai.r,&kong)!=EOF&&pai.s!='#'){
        stack<edge> dui;
        dui.push(pai);
        duis.push_back(dui);
        if(duis.size()==52){
            flag=1;
            int wz=0;
            for(wz=0;wz<duis.size();wz++){
                if(wz>=3&&pan(duis[wz].top(),duis[wz-3].top())){
                    duis[wz-3].push(duis[wz].top());
                    duis[wz].pop();
                    if(duis[wz].empty())  duis.erase(duis.begin()+wz);
                    wz=wz-4;
                }
                if(wz>=1&&pan(duis[wz].top(),duis[wz-1].top())){
                    duis[wz-1].push(duis[wz].top());
                    duis[wz].pop();
                    if(duis[wz].empty())  duis.erase(duis.begin()+wz);
                    wz=wz-2;
                }
            }
            if(duis.size()==1)
                printf("1 pile remaining:");
            else
                printf("%d piles remaining:",duis.size());
            for(int i=0;i<duis.size();i++)
                printf(" %d",duis[i].size());
            printf("\n");
        }
        if(flag)    duis.clear();
        flag=0;
    }
    return 0;
}
