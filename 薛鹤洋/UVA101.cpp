/*
紫薯原题，因为有几堆是固定的，但没堆的高度不一定，所以用数组表示堆，用vector存高度。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int n,a,b;

string s1,s2;

vector<int> pile[maxn+10];

void find_block(int a,int& p,int& h){
    for(p=0;p<n;p++){
        for(h=0;h<pile[p].size();h++)
                if(pile[p][h]==a) return ;
    }
}

void clear_above(int p,int h){
    for(int i=h+1;i<pile[p].size();i++){
        int b=pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
}

void pile_onto(int p,int h,int p2){
   for(int i=h;i<pile[p].size();i++)
        pile[p2].push_back(pile[p][i]);
   pile[p].resize(h);
}

void print(){
   for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int j=0;j<pile[i].size();j++) printf(" %d",pile[i][j]);
        printf("\n");
   }
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) pile[i].push_back(i);
    while(cin>>s1&&s1!="quit"){
        cin>>a>>s2>>b;
        int pa,pb,ha,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa==pb) continue;
        if(s2=="onto") clear_above(pb,hb);
        if(s1=="move") clear_above(pa,ha);
        pile_onto(pa,ha,pb);
    }
    print();
    return 0;
}
