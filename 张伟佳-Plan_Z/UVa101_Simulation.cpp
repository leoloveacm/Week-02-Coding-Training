/* water */
#include <bits/stdc++.h>
using namespace std;
const int maxn=30;
int pos[maxn], pile[maxn], nxt[maxn], stk[maxn], p, n;

void reset(int x) {
	int cur=pile[pos[x]];
	while (cur!=x) {
		int tmp;
		tmp=nxt[cur];
		pile[pos[x]]=nxt[cur];
		nxt[cur]=pile[cur];
		pile[cur]=cur;
		pos[cur]=cur;
		cur=tmp;
	}
}

void pileOver(int x, int y) {
	p=0;
	int cur=pile[pos[x]];
	while (cur!=x) {
		stk[p++]=cur;
		pile[pos[x]]=nxt[cur];
		cur=nxt[cur];
	}
	stk[p++]=cur;
	pile[pos[x]]=nxt[cur];
	while (p) {
		cur=stk[--p];
		nxt[cur]=pile[pos[y]];
		pile[pos[y]]=cur;
		pos[cur]=pos[y];
	}
}

void show() {
	int ans[30], pp=0;
	bool flag=true;
	for (int i=0;i<n;++i) {
		printf("%d:", i);
		int cur=pile[i];
		pp=0;
		while (cur>=0) {
			if (i!=pos[cur]) flag=false;
			ans[pp++]=cur;
			cur=nxt[cur];
		}
		while (pp--) {
			printf(" %d", ans[pp]);
		}
		printf("\n");
	}
	/*
	if (flag) printf("Pos check all clear.\n");
	else printf("Pos wrong.\n");
	*/
}

int main() {
	int x, y;
	char dir[10];
	scanf("%d", &n);
	for (int i=0;i<n;++i) pos[i]=pile[i]=i;
	memset(nxt, 0xff, sizeof(nxt));
	for (;;) {
		scanf("%s", dir);
		if (strcmp(dir, "quit")==0) {
			break;
		}else if (strcmp(dir, "move")==0) {
			scanf("%d%s%d", &x, dir, &y);
			if (x==y || pos[x]==pos[y]) continue;
			if (strcmp(dir, "onto")==0) {		// move onto
				reset(x);
				reset(y);
				pile[pos[x]]=nxt[x];
				nxt[x]=pile[pos[y]];
				pile[pos[y]]=x;
				pos[x]=pos[y];
			}else {								// move over
				reset(x);
				pile[pos[x]]=nxt[x];
				nxt[x]=pile[pos[y]];
				pile[pos[y]]=x;
				pos[x]=pos[y];
			}
		}else if (strcmp(dir, "pile")==0) {
			scanf("%d%s%d", &x, dir, &y);
			if (x==y || pos[x]==pos[y]) continue;
			if (strcmp(dir, "onto")==0) {		// move onto
				reset(y);
				pileOver(x, y);
			}else {								// move over
				pileOver(x, y);
			}
		}
		//show();
	}
	show();
	return 0;
}