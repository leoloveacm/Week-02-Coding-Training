/*
递归时上一级需要下一级必须是叶子结点时获得的答案才有效
所以下级的函数返回给上级答案和是否为叶子结点的信息。
*/
#include <bits/stdc++.h>
using namespace std;

char input() {
	char ch;
	scanf("%c", &ch);
	while (ch==' '||ch=='\n') 
		scanf("%c", &ch);
	return ch;
}

bool solve(int v, int &leaf) {
	int tmp, value;
	scanf("%d", &value);
	tmp=input();
	int l=0, r=0, ans=0;
	if (tmp=='(') {
		if (solve(v-value, l)) ans=1;
		tmp=input();
		if (solve(v-value, r)) ans=1;
		tmp=input();
		if (l && r) ans=(v==value);
	}else leaf=1;
	return ans;
}

int main() {
	int n, tmp;
	while (scanf("%d", &n)!=EOF) {
		input();
		if (solve(n, tmp)) printf("yes\n");
		else printf("no\n");
	}
	return 0;
}