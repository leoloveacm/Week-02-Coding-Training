#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double pi=acos(-1);
int main(){
	int T,nc(1);
	double a,b,ans1,ans2;
	scanf("%d",&T);
	//cout<<T<<endl;
	while(T--){
        char c;
        cin>>a;
        getchar();
        getchar();
        getchar();
        cin>>b;
        //cout<<a<<" "<<b<<endl;
        double degree=atan(b/a);
        //cout<<a<<" "<<b<<endl;
        double r=100.0/(degree+cos(degree));
        ans1=2*r*cos(degree);
        ans2=2*r*sin(degree);
        printf("Case %d: %.10lf %.10lf\n",nc++,ans1,ans2);
	}
	return 0;
}
