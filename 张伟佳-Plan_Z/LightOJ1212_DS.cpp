/* water */
#include <bits/stdc++.h>
using namespace std;
const int maxn=20;
int q[maxn], front, rear, n;
 
void init() {
    front=rear=0;
}
 
inline int getLen() {
    return (rear-front+maxn)%maxn;
}
 
void pushLeft(int x) {
    if (getLen()==n) {
        cout<<"The queue is full\n";
        return;
    }
    cout<<"Pushed in left: "<<x<<endl;
    front=(front+maxn-1)%maxn;
    q[front]=x;
}
 
void pushRight(int x) {
    if (getLen()==n) {
        cout<<"The queue is full\n";
        return;
    }
    cout<<"Pushed in right: "<<x<<endl;
    q[rear]=x;
    rear=(rear+1)%maxn;
}
 
void popLeft() {
    if (getLen()==0) {
        cout<<"The queue is empty\n";
        return;
    }
    cout<<"Popped from left: "<<q[front]<<endl;
    front=(front+1)%maxn;
}
 
void popRight() {
    if (getLen()==0) {
        cout<<"The queue is empty\n";
        return;
    }
    cout<<"Popped from right: "<<q[(rear-1+maxn)%maxn]<<endl;
    rear=(rear+maxn-1)%maxn;
}
 
int main() {
    int m, T, icase=1;
    cin>>T;
    while (T--) {
        init();
        cin>>n>>m;
        cout<<"Case "<<icase++<<":"<<endl;
        while (m--) {
            string dir;
            int x;
            cin>>dir;
            if (dir=="pushLeft") {
                cin>>x;
                pushLeft(x);
            }else if (dir=="pushRight") {
                cin>>x;
                pushRight(x);
            }else if (dir=="popLeft") {
                popLeft();
            }else if (dir=="popRight") {
                popRight();
            }
        }
    }
    return 0;
}