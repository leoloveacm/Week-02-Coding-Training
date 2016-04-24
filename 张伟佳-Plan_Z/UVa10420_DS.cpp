/* water */
#include <bits/stdc++.h>
using namespace std;
map<string, int> mp;
set<string> dic;

int main() {
	int n;
	mp.clear();
	dic.clear();
	scanf("%d%*c", &n);
	while (n--) {
		char str[100];
		string nation;
		int p=0;
		gets(str);
		nation.clear();
		while (str[p]!=' ') nation+=str[p++];
		nation+='\0';
		++mp[nation];
		dic.insert(nation);
	}
	for (set<string>::iterator it=dic.begin(); it!=dic.end(); ++it) {
		printf("%s %d\n", it->c_str(), mp[*it]);
	}
	return 0;
}