/* water */
#include <bits/stdc++.h>
using namespace std;
const int maxn=52;
struct Card {
	char type, rank;
	Card() {}
	Card(char *in): rank(in[0]), type(in[1]) {}
	bool operator == (const Card &rhs) const {
		return type==rhs.type||rank==rhs.rank;
	}
};
Card a[maxn];
int pile[maxn], next[maxn], ans[maxn];

inline void move(int x, int y) {
	//printf("%d to %d\n", x, y);
	int tmp=pile[x];
	pile[x]=next[pile[x]];
	next[tmp]=pile[y];
	pile[y]=tmp;
}

int main() {
	char in[3];
	int cnt;
	while (scanf("%s", in)!=EOF) {
		if (in[0]=='#') break;
		a[0]=Card(in);
		for (int i=1;i<maxn;++i) {
			scanf("%s", in);
			a[i]=Card(in);
		}
		for (int i=0;i<maxn;++i) pile[i]=i;
		memset(next, 0xff, sizeof(next));
		bool flag=true;
		while (flag) {
			flag=false;
			for (int i=1;i<maxn;++i) {
				if (pile[i]<0) continue;
				int k=0, j;
				for (j=i-1;j>=0&&k<3;--j) {
					if (pile[j]>=0) ++k;
				}
				++j;
				if (k==3 && a[pile[i]]==a[pile[j]]) {
					flag=true;
					move(i, j);
					break;
				}
				k=0;
				for (j=i-1;j>=0&&k<1;--j) {
					if (pile[j]>=0) ++k; 
				}
				++j;
				if (k==1 && a[pile[i]]==a[pile[j]]) {
					flag=true;
					move(i, j);
					break;
				}
			}
			/*
			printf("%d\n", flag);
			for (int i=0;i<maxn;++i) {
				int p=pile[i];
				int cnt=0;
				if (p>=0) ++cnt;
				while (next[p]) {
					++cnt;
					p=next[p];
				}
				printf("%d ", cnt);
			}
			printf("\n");
			*/
		}
		memset(ans, 0, sizeof(ans));
		cnt=0;
		for (int i=0;i<maxn;++i) {
			int p=pile[i];
			if (p<0) continue;
			ans[i]=1;
			++cnt;
			while (next[p]>=0) {
				++ans[i];
				p=next[p];
			}
		}
		printf("%d pile%sremaining: ", cnt, cnt>1?"s ":" ");
		int k=0;
		for (int i=0;i<maxn;++i) {
			if (ans[i]) {
				++k;
				printf("%d%c", ans[i], k==cnt?'\n':' ');
			}
		}
	}
	return 0;
}
/*
1A 2A 2B 3B
*/