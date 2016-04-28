#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
int loc[30];
int shu[30][30];
int top[25];
int buffer[30];
void qingchu(int a){
    int tmp;
    int loca=loc[a];
    while(shu[loca][top[loca]]!=a){
        tmp=shu[loca][top[loca]--];
        loc[tmp]=tmp;
        shu[tmp][++top[tmp]]=tmp;
    }
}
void yidong(int a,int b){
    int loca,locb;
    loca=loc[a];
    locb=loc[b];
    int k=-1;
    while(shu[loca][top[loca]]!=a)
        buffer[++k]=shu[loca][top[loca]--];
    loc[a]=locb;
    shu[locb][++top[locb]]=a;
    top[loca]--;
    while(k>=0){
        loc[buffer[k]]=locb;
        shu[locb][++top[locb]]=buffer[k--];
    }
}
int main(){
    string str1,str2;
    int n;
    int a,b;
    while(scanf("%d",&n)!=EOF){
        memset(top,0,sizeof(top));
        for(int i=0;i<n;i++)
        {
            shu[i][0]=i;
            loc[i]=i;
            top[i]=0;
        }
        while(cin>>str1){
            if(str1=="quit") break;
            cin>>a>>str2>>b;
            if(loc[a]==loc[b]||a==b) {
                continue;
            }
            if(str1=="move"&&str2=="onto"){
                qingchu(a);
                qingchu(b);
                yidong(a,b);
            }
            else if(str1=="move"&&str2=="over"){
                qingchu(a);
                yidong(a,b);
            }
            else if(str1=="pile"&&str2=="onto"){
                qingchu(b);
                yidong(a,b);
            }
            else if(str1=="pile"&&str2=="over"){
                yidong(a,b);
            }
            else;
        }
        for ( int i = 0 ; i < n ; ++ i ) {
            printf("%d:",i);
            int k=0;
            while(k<=top[i])
                printf(" %d",shu[i][k++]);
            printf("\n");
        }
    }
	return 0;
}
