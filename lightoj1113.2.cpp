#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <string>
using namespace std;
stack<string> s1;
stack<string> s2;
int main()
{
    string str,du;
    int T,nc=1;
    scanf("%d",&T);
    while(T--)
    {
        while(!s2.empty())
            s2.pop();
        while(!s1.empty())
            s1.pop();
        s1.push("http://www.lightoj.com/");
        printf("Case %d:\n",nc++);
        while(1)
        {
            cin>>str;
            if(str[0]=='Q')
                break;
            if(str[0]=='B')
            {
                if(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                    if(s1.empty())
                    {
                        s1.push(s2.top());
                        s2.pop();
                        cout<<"Ignored"<<endl;
                    }
                    else
                        cout<<s1.top()<<endl;
                }
            }
            if(str[0]=='F')
            {
                if(!s2.empty())
                {
                    s1.push(s2.top());
                    s2.pop();
                    cout<<s1.top()<<endl;
                }
                else
                    cout<<"Ignored"<<endl;
            }
            if(str[0]=='V')
            {
                cin>>du;
                s1.push(du);
                while(!s2.empty())
                    s2.pop();
                cout<<du<<endl;
            }
        }
    }
    return 0;
}
