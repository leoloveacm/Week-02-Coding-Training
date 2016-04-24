/* water */
#include <bits/stdc++.h>
using namespace std;
const int maxn=30;
bool vis[25][25];
int n, m, fw[maxn];
deque<int> que;

int main() {
	int T, icase=1, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		ans=0;
		que.clear();
		memset(vis, false, sizeof(vis));
		memset(fw, 0xff, sizeof(fw));
		for (int i=0;i<n;++i) que.push_back(i);
		int p=0;
		for (;;p=(p+1)%m) {
			ans+=5;
			if (fw[p]>=0) {
				que.push_back(fw[p]);
				fw[p]=-1;
			}
			for (deque<int>::iterator it=que.begin();it!=que.end();++it) {
				int tmp=*it;
				if (!vis[tmp][p]) {
					fw[p]=tmp;
					vis[tmp][p]=true;
					que.erase(it);
					break;
				}
			}
			bool flag=true;
			for (int i=0;i<n&&flag;++i) {
				for (int j=0;j<m;++j) 
					if (!vis[i][j]) {
						flag=false;
						break;
					}
			}
			if (flag) break;
		}
		ans+=m*5;
		printf("Case %d: %d\n", icase++, ans);
	}
	return 0;
}