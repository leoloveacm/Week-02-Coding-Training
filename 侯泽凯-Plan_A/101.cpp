//数据结构的嵌套（容易混乱）
#include<bits/stdc++.h>

int change[100];
int pos[100];

using namespace std;
int main()
{
	stack<int>s[100];
	string op,clas;
	int from,to;
	int t;

	cin>>t;
	getchar();

	for(int i=0;i<t;i++)
	{
		s[i].push(i);
		pos[i]=i;
	}

	while(cin>>op)
	{
		if(op=="quit")break;

		if(op=="move")
		{
			cin>>from>>clas>>to;
			if (pos[from] == pos[to])continue;

			if(clas=="onto")
			{
				while(s[pos[from]].top() != from)
				{
					s[s[pos[from]].top() ].push(s[pos[from]].top());
					pos[s[pos[from]].top()] = s[pos[from]].top();
					s[pos[from]].pop();
				}
				while(s[pos[to]].top() != to)
				{
					s[s[pos[to]].top() ].push(s[pos[to]].top());
					pos[s[pos[to]].top()] = s[pos[to]].top();
					s[pos[to]].pop();
				}
				s[pos[to]].push(s[pos[from]].top());
				s[pos[from]].pop();
				pos[from] = pos[to];
			}
			else if(clas=="over")
			{
				while(s[pos[from]].top()!=from)
				{
					s[s[pos[from]].top() ].push(s[pos[from]].top());
					pos[s[pos[from]].top()] = s[pos[from]].top();
					s[pos[from]].pop();
				}
				s[pos[to]].push(from);
				s[pos[from]].pop();
				pos[from] = pos[to];
			}
		}

		else if(op=="pile")
		{
			cin>>from>>clas>>to;
			if (pos[from] == pos[to])continue;

			if(clas=="onto")
			{
				int k = 0;
				int temp[200];
				while(s[pos[from]].top() != from)
				{
					temp[k++] = s[pos[from]].top();
					pos[s[pos[from]].top()] = pos[to];
					s[pos[from]].pop();
				}
				s[pos[from]].pop();
				temp[k] = from;
				pos[from] =pos[to];
				while(s[pos[to]].top() !=to)
				{
					s[ s[pos[to]].top() ].push(s[pos[to]].top());
					pos[s[pos[to]].top()] = s[pos[to]].top();
					s[pos[to]].pop();
				}
				for(int w = k ;w >= 0; w--)
					s[pos[to]].push(temp[w]);
			}
			else if(clas=="over")
			{
				int k = 0;
				int temp[200];
				while(s[pos[from]].top() != from)
				{
					temp[k++] = s[pos[from]].top();
					pos[s[pos[from]].top()] = pos[to];
					s[pos[from]].pop();
				}
				s[pos[from]].pop();
				temp[k] = from;
				pos[from] = pos[to];
				for(int w = k ;w >= 0; w--)
					s[pos[to]].push(temp[w]);
			}
		}
	}

	int j;
	for(int i = 0;i < t;i++)
	{
		cout << i <<":";
		for( j = 0 ;!s[i].empty();j++)
		{
			change[j] =  s[i].top();
			s[i].pop();
		}
		for (j = j -1; j >= 0;j--)
			cout<<" "<<change[j];
		cout << endl;
	}

	return 0;
}
