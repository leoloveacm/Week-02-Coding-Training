//计算s到t的权值小于p时的边的最大长度
//这个题不会啊...想了好久，但是想法里总有bug，
//之前想用dij算法在找最短路的过程中更新路径包含的边的最大值，但是写了一半意识到在map存图的时候已经有一部分权值的数据丢失了
//前向星在底下代码中的处理我并不理解
//找到的AC代码只能明白后期需要在小于p的情况下更新得到最大边长值，这块我也考虑到了，但是前期的处理并不懂
//求讲解...
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct edge {
  int to, w;
  edge() {}
  edge(int a, int b) : to(a), w(b) {}
  bool operator <(const edge &o) const {
    return w > o.w;
  }
};

const int inf = 1000001 + 100;

vector<int> Dijkstra(vector<vector<edge> > &g, int s) {
  vector<int> d(g.size(), inf);
  d[s] = 0;
  priority_queue<edge> q;
  q.push(edge(s, 0));
  while (!q.empty()) {
    int cur  = q.top().to;
    int dist = q.top().w;
    q.pop();

    if (dist > d[cur]) continue;
    for (int i = 0; i < g[cur].size(); ++i) {
      int to = g[cur][i].to;
      int w_extra =  g[cur][i].w;
      if (dist + w_extra < d[to]) {
        d[to] = dist + w_extra;
        q.push(edge(to, d[to]));
      }
    }
  }

  return d;
}

void solve() {
  int n, m, s, t, p;
  cin >> n >> m >> s >> t >> p;
  vector<vector<edge> > g1(n), g2(n);
  int u, v, w;
  for (int i = 0; i < m; ++i) {
    cin >> u >> v >> w;
    u--;v--;
    g1[u].push_back(edge(v, w));//to
    g2[v].push_back(edge(u, w));//from
  }

  s--; t--;

  vector<int> ds = Dijkstra(g1, s);//s is the begin
  vector<int> dt = Dijkstra(g2, t);//t is the end

  int best = -1;
  for (int i = 0; i < g1.size(); ++i) {
    for (int j = 0; j < g1[i].size(); ++j) {
      u = i, v = g1[i][j].to, w = g1[i][j].w;
      if (ds[u] + w + dt[v] <= p) {
        best = max(best, w);
      }
    }
  }

  printf("%d\n", best);
}

int main() {
  int T; cin >> T;
  for (int i = 0; i < T; ++i) {
    printf("Case %d: ", i + 1);
    solve();
  }
  return 0;
}
