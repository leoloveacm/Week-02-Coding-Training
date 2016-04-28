#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;
int a,b;
int loc[30];
int n;
struct Blocks{
    int sizes;
    int shu[30];
    void push();
}wood[30];
void ini(){
    int i=0;
    for(i=0;i<n;i++){
        wood[i].sizes=0;
        wood[i].shu[0]=i;
        loc[i]=i;
    }
}
void fun1(){
    int loca,locb;
    loca=loc[a];
    locb=loc[b];
    while(1){//a shangmiandequdiao
        if(wood[loca].shu[wood[loca].sizes]==a) break;
        int tmp=wood[loca].shu[wood[loca].sizes];
        int loct=loc[tmp];
        wood[loct].shu[wood[loct].sizes+1]=tmp;
        wood[loct].sizes++;
        wood[loca].shu[wood[loca].sizes]=0;
        wood[loca].sizes--;
        loc[tmp]=tmp;
    }
    while(1){//b shangmiandequdiao
        if(wood[locb].shu[wood[locb].sizes]==b) break;
        int tmp=wood[locb].shu[wood[locb].sizes];
        int loct=loc[tmp];
        wood[loct].shu[wood[loct].sizes+1]=tmp;
        wood[loct].sizes++;
        wood[locb].shu[wood[locb].sizes]=0;
        wood[locb].sizes--;
        loc[tmp]=tmp;
    }
    //jiashangqu
    wood[locb].shu[wood[locb].sizes+1]=a;
    loc[a]=locb;
    wood[locb].sizes++;
    wood[loca].shu[wood[loca].sizes]=0;
    wood[loca].sizes--;
}
void fun2(){
    int loca,locb;
    loca=loc[a];
    locb=loc[b];
    while(1){//a shangmiandequdiao
        if(wood[loca].shu[wood[loca].sizes]==a) break;
        int tmp=wood[loca].shu[wood[loca].sizes];
        int loct=loc[tmp];
        wood[loct].shu[wood[loct].sizes+1]=tmp;
        wood[loct].sizes++;
        wood[loca].shu[wood[loca].sizes]=0;
        wood[loca].sizes--;
        loc[tmp]=tmp;
    }//jiashangqu
    wood[locb].shu[wood[locb].sizes+1]=a;
    loc[a]=locb;
    wood[locb].sizes++;
    wood[loca].shu[wood[loca].sizes]=0;
    wood[loca].sizes--;
}
void fun3(){
    int loca,locb;
    loca=loc[a];
    locb=loc[b];
    int i;
    while(1){//b qudiaoshangmiande
        if(wood[locb].shu[wood[locb].sizes]==b) break;
        int tmp=wood[locb].shu[wood[locb].sizes];
        int loct=loc[tmp];
        wood[loct].shu[wood[loct].sizes+1]=tmp;
        wood[loct].sizes++;
        wood[locb].shu[wood[locb].sizes]=0;
        wood[locb].sizes--;
        loc[tmp]=tmp;
    }
    int sizes=wood[loca].sizes+wood[locb].sizes;
    for(int i=sizes;i>wood[locb].sizes;i--){
        int tmp=wood[loca].shu[wood[loca].sizes];
        wood[locb].shu[i]=tmp;
        loc[tmp]=locb;
        wood[loca].shu[wood[loca].sizes]=0;
        wood[loca].sizes--;
    }
    wood[locb].sizes=sizes;
}
void fun4(){
    int loca,locb;
    loca=loc[a];
    locb=loc[b];
    int sizea=wood[loca].sizes;
    while(wood[loca].shu[--sizea]!=a);
    sizea++;
    int sizes=sizea+wood[locb].sizes;
    //cout<<"sizes: "<<sizes<<endl;
    for(int i=sizes;i>wood[locb].sizes;i--){
        int tmp=wood[loca].shu[wood[loca].sizes];
        wood[locb].shu[i]=tmp;
        loc[tmp]=locb;
        wood[loca].shu[wood[loca].sizes]=0;
        wood[loca].sizes--;
    }
    wood[locb].sizes=sizes;
}
int main(){
	string str1,str2;
    scanf("%d",&n);
    ini();
    while(cin>>str1){
        if(str1=="quit") break;
        cin>>a>>str2>>b;
        if(a==b||loc[a]==loc[b]) {
            continue;
        }
        if(str1=="move"&&str2=="onto"){
            fun1();
        }
        else if(str1=="move"&&str2=="over"){
            fun2();
        }
        else if(str1=="pile"&&str2=="onto"){
            fun3();
        }
        else if(str1=="pile"&&str2=="over"){
            fun4();
        }
        else;
        /*for(int i=0;i<n;i++){
        cout<<i<<":";
        for(int j=0;wood[i].sizes>=0&&j<=wood[i].sizes;j++)
            cout<<" "<<wood[i].shu[j];
        cout<<endl;
    }*/
    }
    for(int i=0;i<n;i++){
        cout<<i<<":";
        for(int j=0;wood[i].sizes>=0&&j<=wood[i].sizes;j++)
            cout<<" "<<wood[i].shu[j];
        cout<<endl;
    }
	return 0;
}
