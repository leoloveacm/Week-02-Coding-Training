/* water */
#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int dis[maxn], k, n;

bool judge(int x) {					// true mid+1~r false l~mid
	int cnt=0, sum=0;
	for (int i=0;i<n;++i) {
		if (sum+dis[i]>x) {
			++cnt;
			sum=dis[i];
		}else {
			sum+=dis[i];
		}
	}
	++cnt;
	if (cnt>k) return true;
	return false;
}

int main() {
	int T, icase=1, l, r;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		++k;
		++n;
		l=0;
		r=0;
		for (int i=0;i<n;++i) {
			scanf("%d", dis+i);
			r+=dis[i];
			l=max(l, dis[i]);
		}
		while (l<r) {
			int mid=(l+r)>>1;
			if (judge(mid)) {
				l=mid+1;
			}else {
				r=mid;
			}
		}
		printf("Case %d: %d\n", icase++, l);
		int sum=0, cnt=0;
		for (int i=0;i<n;++i) {
			if (sum+dis[i]>l||n-i==k-cnt-1) {
				printf("%d\n", sum);
				sum=dis[i];
				++cnt;
			}else sum+=dis[i];
		}
		printf("%d\n", sum);
	}
	return 0;
}