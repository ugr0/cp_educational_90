#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

struct Edge {
  int to;
  long long w;
  Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template <class T>
bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  } else
    return false;
}

int N, M;
vector<long long> dist;

void dijkstra(int stt, Graph G) {
  dist.assign(N, INF);
  dist[stt] = 0;

  // (d[v], v)のペアを要素としたヒープを作る
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      que;

  que.push(make_pair(dist[stt], stt));

  // ダイクストラ法の反復を開始
  while (!que.empty()) {
    // v: 使用済みでない頂点のうちd[v]が最小の頂点
    // d: vに対するキー値
    int v = que.top().second;
    long long d = que.top().first;
    que.pop();

    // d > dist[v]は(d, v)がゴミであることを意味する
    if (d > dist[v]) continue;

    // 頂点vを始点とした各辺を緩和
    for (auto e : G[v]) {
      if (chmin(dist[e.to], dist[v] + e.w)) {
        // 更新があるならヒープに新たに挿入
        que.push(make_pair(dist[e.to], e.to));
      }
    }
  }
}

int main() {
  cin >> N >> M;

  Graph G(N);
  for (int i = 0; i < M; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    --a, --b;
    G[a].push_back(Edge(b, w));
    G[b].push_back(Edge(a, w));
  }

  // dijkstra
  dijkstra(0, G);
  vector<long long> dist_0(N);
  for (int i = 0; i < N; i++) dist_0[i] = dist[i];
  dijkstra(N - 1, G);
  vector<long long> dist_N(N);
  for (int i = 0; i < N; i++) dist_N[i] = dist[i];

  for (int k = 0; k < N; k++) {
    cout << dist_0[k] + dist_N[k] << endl;
  }
}
