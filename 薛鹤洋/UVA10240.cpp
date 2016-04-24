/*
stl map水题
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

const int maxn=100;

using namespace std;

int n;

map<string,int> m;

char a[maxn+10],b[maxn+10];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",a);
        gets(b);
        m[string(a)]++;
    }
    map<string,int>::iterator it=m.begin();
    for(;it!=m.end();++it){
        printf("%s %d\n",it->first.c_str(),it->second);
    }
    return 0;
}
