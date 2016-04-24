//题是不难，输入太恶心。。然后看了别人的代码。。cin还能这样玩。。。。
#include<iostream>
#include<string>
using namespace std;
bool scan(int nSum,int n,bool *p) {
    int nChild;
    cin>>(char&)nChild;
    bool br=false,p1=false,p2=false;
    if (!(*p=((cin>>nChild)==0))){
        nSum+=nChild;
        br=scan(nSum,n,&p1)|scan(nSum,n,&p2);
        if(p1&&p2&&nSum==n) br=1;
    }
    cin.clear();
    cin>>(char&)nChild;
    return br;
}
int main(){
    bool p;
    int n;
    for(;cin>>n;){
        cout<<(scan(0,n,&p)?"yes":"no")<<endl;
    }
    return 0;
}
