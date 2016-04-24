//在vector里套用stack模拟纸牌游戏
#include<bits/stdc++.h>
using namespace std;

struct poker{
	char num;
	char col;
}temp;

bool is_match(poker a,poker b)
{
	if(a.num==b.num||a.col==b.col) return 1;
	return 0;
}
int main()
{
	vector<stack<poker> >pile;
	stack<poker>s;
	char jug,sec;

	while(cin>>jug)
	{
		if(jug=='#')break;
		cin>>sec;
		temp.num=jug;
		temp.col=sec;
		s.push(temp);
		pile.push_back(s);
		s.pop();
		if(pile.size()==52)
		{
			while(1)
			{
				int i;
				for(i=0;i!=pile.size();i++)
				{
					if(i>=3&&is_match(pile[i].top(),pile[i-3].top()))
					{
						pile[i-3].push(pile[i].top());
						pile[i].pop();
						break;
					}
					if(i>=1&&is_match(pile[i].top(),pile[i-1].top()))
					{
						pile[i-1].push(pile[i].top());
						pile[i].pop();
						break;
					}
				}
				if(i==pile.size()) break;
				else if(pile[i].empty())
					   pile.erase(pile.begin()+i);
			}
			cout<<pile.size()<<(pile.size()==1?" pile remaining:":" piles remaining:");
			for(int i=0;i!=pile.size();i++) cout<<' '<<pile[i].size();
			cout<<endl;
			pile.clear();
		}

	}
	return 0;
}
