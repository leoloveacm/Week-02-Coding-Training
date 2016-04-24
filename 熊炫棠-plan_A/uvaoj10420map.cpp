//用map吧，最水的一道
#include<cstdio>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int main(){
    map<string,int> q;
    char a[80];
  //  scanf("%s",a);
 //   printf("%s",a);
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",a);
        q[string(a)]++;
        gets(a);
    }
    map<string,int>::iterator it;
    for(it=q.begin();it!=q.end();it++){
        printf("%s %d\n",it->first.c_str(),it->second);
    }
    return 0;
}
