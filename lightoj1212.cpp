#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;
deque <int> dq;
string str;
int main(){
	int T,nc(1);
	scanf("%d",&T);
	int full,n,d;
	while(T--){
        scanf("%d%d",&full,&n);
        printf("Case %d:\n",nc++);
        dq.clear();
        while(n--){
            cin>>str;
            if(str=="pushLeft"){
                cin>>d;
                if(dq.size()==full)
                    cout<<"The queue is full"<<endl;
                else{
                    dq.push_back(d);
                    cout<<"Pushed in left: "<<d<<endl;
                }
            }
            if(str=="pushRight"){
                cin>>d;
                if(dq.size()==full)
                    cout<<"The queue is full"<<endl;
                else{
                    dq.push_front(d);
                    cout<<"Pushed in right: "<<d<<endl;
                }
            }
            if(str=="popLeft"){
                if(dq.size()==0)
                    cout<<"The queue is empty"<<endl;
                else{
                    d=dq.back();
                    cout<<"Popped from left: "<<d<<endl;
                    dq.pop_back();
                }
            }
            if(str=="popRight"){
                if(dq.size()==0)
                    cout<<"The queue is empty"<<endl;
                else{
                    d=dq.front();
                    cout<<"Popped from right: "<<d<<endl;
                    dq.pop_front();
                }
            }
        }
	}
	return 0;
}
