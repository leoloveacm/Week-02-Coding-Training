/*
直接推公式出结果
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

//const int maxn=;

using namespace std;

int t;

double width,length;

int C(double mid){
        double sum=2*mid+2*atan(width/length)*mid*(sqrt(length*length+width*width)/length);
        if(sum>400) return 1;
        else return 0;
}

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        scanf("%lf : %lf",&length,&width);
        double lb=0,ub=1000;
        for(int i=0;i<100;i++){
                double mid=(lb+ub)/2;
                if(C(mid)) ub=mid;
                else lb=mid;
        }
        printf("Case %d: %.8f %.8f\n",h,lb,lb*width/length);
    }
    return 0;
}
