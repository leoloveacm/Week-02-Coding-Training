/* water */
#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1);

int main() {
	int T, icase=1;
	double a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf : %lf", &a, &b);
		double alpha=atan(a/b);
		double r=200.0/(2.0*sin(alpha)+(pi-2*alpha));
		printf("Case %d: %.8f %.8f\n", icase++, 2*r*sin(alpha), 2*r*cos(alpha));
	}
	return 0;
}