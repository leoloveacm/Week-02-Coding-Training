/*
这题用二分卡精度，可以直接算公式。
*/
#include <bits/stdc++.h>
using namespace std;
const double eps=1e-12;
double a, b;

inline bool judge(double x) {
	return sqrt(x*x+x*x*b/a*b/a)*atan(b/a)+x>=200.0;
}

int main() {
	int T, icase=1;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf : %lf", &a, &b);
		double l, r;
		l=0.0;
		r=400.0;
		while (l<r-eps) {
			double mid=(l+r)/2;
			if (judge(mid)) {
				r=mid;
			}else {
				l=mid;
			}
		}
		printf("Case %d: %.8f %.8f\n", icase++, l, l/a*b);	
	}
	return 0;
}