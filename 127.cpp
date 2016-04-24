//嵌套数据结构，注意stl的容器用完要清空，最重要的：认真读题！！！
#include<bits/stdc++.h>
using namespace std;

struct poker{
	char num;
	char col;
}temp;

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

		for(int i=1;i<=51;i++)
		{
			cin>>temp.num>>temp.col;
			s.push(temp);
			pile.push_back(s);
			s.pop();
		}

		for(int i=0;i<pile.size();i++)
		{
			if((i>=3)&&(pile[i].top().num==pile[i-3].top().num||pile[i].top().col==pile[i-3].top().col))
			{
				pile[i-3].push(pile[i].top());
				pile[i].pop();
				if(pile[i].empty())
				{
					pile.erase(pile.begin()+i);
				}
				i=0;
			}
			else if((i>=1)&&(pile[i].top().num==pile[i-1].top().num||pile[i].top().col==pile[i-1].top().col))
			{
				pile[i-1].push(pile[i].top());
				pile[i].pop();
				if(pile[i].empty())
				{
					pile.erase(pile.begin()+i);
				}
				i=0;
			}
		}

		cout<<pile.size();
		if(pile.size()>1)
		{
			cout<<" piles remaining:";
		}
		else
		{
			cout<<" pile remaining:";
		}
		for(int i=0;i<pile.size();i++)
		{
			cout<<" "<<pile[i].size();
		}
		cout<<endl;

		pile.clear();

	}
	return 0;
}
