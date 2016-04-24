//map本身就是排好序的，用迭代器直接输出即可，新技能get
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string,int> m;
    int T;
    cin>>T;
    while(T--)
    {
        string s,p;
        cin>>s;
        getchar();          //吸收留在缓冲区的空格
        getline(cin,p);
        if(m[s]!=0)
            m[s]++;
        else
            m[s]=1;
    }
    map<string,int>::iterator i;

    for(i=m.begin();i!=m.end();i++)
		cout<<(*i).first<<" "<<(*i).second<<endl;
    return 0;
}
