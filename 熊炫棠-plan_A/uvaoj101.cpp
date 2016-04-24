//模拟了很久，，读懂题很重要。然后就是有的操作有些重复可以写个函数，比如把上面的全放回去。。然后我一开始写的vector<list<stack> >发现不能遍历。。。
#include<cstdio>
#include<iostream>
#include<cstring>
#include<stack>
#include<vector>
#include<list>
using namespace std;
int n;
int posi[30];
vector<list<int> > duis(30);//这儿注意要写出多少（30），不然直接就错了
void clearup(int x){
    list<int>::iterator it=duis[posi[x]].begin();
    while(*it!=x){//duis[posi[x]].top()=*it
        duis[*it].push_front(*it);
        duis[posi[x]].pop_front();
        posi[*it]=*it;
        it++;
    }
}
void mn(int x,int y){
    clearup(x);
    clearup(y);
    duis[posi[y]].push_front(x);
    duis[posi[x]].pop_front();
    posi[x]=posi[y];
}
void mv(int x,int y){
    clearup(x);
    duis[posi[y]].push_front(x);
    duis[posi[x]].pop_front();
    posi[x]=posi[y];
}
void pv(int x,int y){
    list<int> ls;
    list<int>::iterator it=duis[posi[x]].begin();
    while(*it!=x)   it++;
    while(it!=duis[posi[x]].begin()){
        duis[posi[y]].push_front(*it);
        if(*it!=x)  posi[*it]=posi[y];
        duis[posi[x]].erase(it);
        it--;
    }
    duis[posi[y]].push_front(*it);
    if(*it!=x)  posi[*it]=posi[y];
    duis[posi[x]].erase(it);
    posi[x]=posi[y];
}
void pn(int x,int y){
    clearup(y);
    pv(x,y);
}
int main(){
    char com[3][20];
    int x,y;
    while(scanf("%d",&n)!=EOF){
       for(int i=0;i<n;i++){
            duis[i].clear();
            duis[i].push_front(i);
            posi[i]=i;

        }
         while(scanf("%s",com[1])!=EOF){
            if(com[1][0]=='q')  break;
            scanf("%d%s%d",&x,com[2],&y);
            if(posi[x]==posi[y])    continue;
            if(com[1][0]=='m')
                if(com[2][1]=='n')
                    mn(x,y);
                else
                    mv(x,y);
            else
                if(com[2][1]=='n')
                    pn(x,y);
                else
                    pv(x,y);
        }
        for(int i=0;i<n;i++){
            printf("%d:",i);
            for(list<int>::iterator it=duis[i].begin();it!=duis[i].end();it++)
                printf("%d ",*it);
            printf("\n");
        }
    }
    return 0;
}
