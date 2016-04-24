/* water */
#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n, s[maxn], g[maxn];
int cnt[10], cnt1[10];

int main() {
	int st, we, sum, icase=1;
	while (scanf("%d", &n) && n) {
		for (int i=0;i<n;++i) scanf("%d", s+i);
		printf("Game %d:\n", icase++);
		for (;;) {
			sum=0;
			st=we=0;
			memset(cnt, 0, sizeof(cnt));
			memset(cnt1, 0, sizeof(cnt1));
			for (int i=0;i<n;++i) {
				scanf("%d", g+i);
				if (g[i]==s[i]) {
					++st;
				}else {
					++cnt[s[i]];
					++cnt1[g[i]];
				}
				sum+=g[i];
			}
			if (sum==0) break;
			for (int i=1;i<=9;++i) we+=min(cnt[i], cnt1[i]);
			printf("    (%d,%d)\n", st, we);
		}
	}
	return 0;
}