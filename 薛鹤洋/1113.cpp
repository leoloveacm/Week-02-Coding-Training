/*
用栈模拟操作，水题。
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

//const int maxn=;

using namespace std;

int t;

string cur,order,top;

stack<string> b,f;

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        printf("Case %d:\n",h);
        cur="http://www.lightoj.com/";
        while(!f.empty()) f.pop();
        while(!b.empty()) b.pop();
        while(cin>>order){
        if(order=="VISIT"){
            b.push(cur);
            cin>>cur;
            cout<<cur<<endl;
            while(!f.empty()) f.pop();
         } else if(order=="BACK"){
              if(b.empty()){printf("Ignored\n");continue;}
              f.push(cur);
              top=b.top(),cur=top,b.pop();
              cout<<top<<endl;
        } else if(order=="FORWARD"){
              if(f.empty()){printf("Ignored\n");continue;}
              b.push(cur);
              top=f.top(),cur=top,f.pop();
              cout<<top<<endl;
        } else break;
        }
    }
    return 0;
}
