/* water */
#include <bits/stdc++.h>
using namespace std;
stack<string> prv, nxt;
string cur;

int main() {
	int T, icase=1;
	cin>>T;
	while (T--) {
		string dir;
		cur="http://www.lightoj.com/";
		cout<<"Case "<<icase++<<":"<<endl;
		for (;;) {
			cin>>dir;
			if (dir=="VISIT") {
				if (cur.size()) prv.push(cur);
				cin>>cur;
				cout<<cur<<endl;
				while (nxt.size()) nxt.pop();
			}else if (dir=="BACK") {
				if (prv.size()) {
					nxt.push(cur);
					cur=prv.top();
					prv.pop();
					cout<<cur<<endl;
				}else {
					cout<<"Ignored"<<endl;
				}
			}else if (dir=="FORWARD") {
				if (nxt.size()) {
					prv.push(cur);
					cur=nxt.top();
					nxt.pop();
					cout<<cur<<endl;
				}else {
					cout<<"Ignored"<<endl;
				}
			}else {
				break;
			}
		}
		while (nxt.size()) nxt.pop();
		while (prv.size()) prv.pop();
	}
	return 0;
}