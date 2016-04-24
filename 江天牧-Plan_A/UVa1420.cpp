//map的简单应用，统计每个国家出现的次数
#include <iostream>
#include<cstdio>
#include<map>
#include<cstring>
char girl[75];

using namespace std;
map<string,int> country;
int main()
{
    int n;
    scanf("%d",&n);
    gets(girl);
    while(n--)
    {
        gets(girl);
        char asd[20];
        sscanf(girl,"%s",asd);
        country[asd]++;
    }

    map<string,int>::iterator it;
    for(it = country.begin();it!=country.end();it++)
        {
            printf("%s %d\n",it->first.c_str(),it->second);
        }
    return 0;
}
