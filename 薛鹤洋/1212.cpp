/*
双端队列的操作
*/
#include<bits/stdc++.h>

#define inf 0x3f3f3f3f

//const int maxn=;

using namespace std;

int t,m,n,num;

string order;

deque<int> q;

int main()
{
    scanf("%d",&t);
    for(int h=1;h<=t;h++){
        printf("Case %d:\n",h);
        q.clear();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++){
             cin>>order;
             if(order=="pushLeft") {
                scanf("%d",&num);
                if(q.size()<n) {
                printf("Pushed in left: %d\n",num);
                q.push_front(num);
                } else printf("The queue is full\n");
             } else if(order=="pushRight") {
                 scanf("%d",&num);
                 if(q.size()<n) {
                 printf("Pushed in right: %d\n",num);
                q.push_back(num);
                 } else printf("The queue is full\n");
             } else if(order=="popLeft") {
                  if(!q.empty()) {
                        printf("Popped from left: %d\n",q.front());
                        q.pop_front();
                  }
                  else printf("The queue is empty\n");
             } else if(order=="popRight"){
                  if(!q.empty()) {
                        printf("Popped from right: %d\n",q.back());
                        q.pop_back();
                  }
                  else printf("The queue is empty\n");
             }
        }
    }
    return 0;
}
