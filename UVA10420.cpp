#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <string>
using namespace std;
map<string,int>mp;
int main(){
	int T;
	string str;
	scanf("%d",&T);
	getchar();
	while(T--){
        cin>>str;
        //cout<<str<<endl;
        getchar();
        mp[str]++;
        getline(cin,str);
	}
	map<string ,int>::iterator it;
	for(it=mp.begin();it!=mp.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
	return 0;
}
