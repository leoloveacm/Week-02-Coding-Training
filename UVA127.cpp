#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;
struct Card{
    char c;
    char color;
};
vector<stack<Card> >p;

bool cmp(Card a,Card b){
    if(a.c==b.c)
        return 1;
    if(a.color==b.color)
        return 1;
    return 0;
}
void solve(){
    while(1){
        int i;
        for(i=0;i!=p.size();i++){
            if(i>=3&&cmp(p[i].top(),p[i-3].top())){
                p[i-3].push(p[i].top());
                p[i].pop();
                break;
            }
            if(i>=1&&cmp(p[i].top(),p[i-1].top())){
                p[i-1].push(p[i].top());
                p[i].pop();
                break;
            }
        }
        if(i==p.size()) break;
        else if(p[i].empty()){
            p.erase(p.begin()+i);
        }
    }
    cout<<p.size();
    if(p.size()==1) cout<<" pile remaining:";
    else cout<<" piles remaining:";
    for(int i=0;i<p.size();i++)
        cout<<" "<<p[i].size();
    cout<<endl;
}
int main(){
    string str;
    int cnt(0),i=0,k=0;
    p.clear();
    stack<Card> s;
    while(!s.empty()) s.pop();
    Card card;
	while(1){
        cin>>str;
        cnt++;
        if(str[0]=='#') break;
        if(cnt==52){
            card.c=str[0];
            card.color=str[1];
            s.push(card);
            p.push_back(s);
            s.pop();
            solve();
            while(!s.empty()) s.pop();
            cnt=0;
            p.clear();
        }
        else{
            card.c=str[0];
            card.color=str[1];
            s.push(card);
            p.push_back(s);
            s.pop();
        }
	}
	return 0;
}
