#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
string str;
stack<string>s1;
stack<string>s2;
int main(){
	int T;
	string du;
	scanf("%d",&T);
	int nc(1);
	while(T--){
        printf("Case %d:\n",nc++);
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
        du="http://www.lightoj.com/";
        s1.push(du);
        while(1){
            cin>>str;
            if(str=="QUIT") break;
            if(str=="VISIT"){
                cin>>du;
                s1.push(du);
                while(!s2.empty())s2.pop();
                cout<<du<<endl;
            }
            if(str=="BACK"&&!s1.empty()){
                s2.push(s1.top());
                s1.pop();
                if(s1.empty()){
                    du="Ignored";
                    cout<<du<<endl;
                    s1.push(s2.top());
                    s2.pop();
                }
                else{
                    cout<<s1.top()<<endl;
                }
            }
            if(str=="FORWARD"&&!s2.empty()){
                if(s2.empty()){
                    du="Ignored";
                    cout<<du<<endl;
                }
                else{
                    s1.push(s2.top());
                    s2.pop();
                    cout<<s1.top()<<endl;
                }
            }
        }
	}
	return 0;
}
