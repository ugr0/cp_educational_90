#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;
vector<int> dist(1 << 18);
const int INF = 1 << 30;
int N;

void getdist(int start, Graph &G) {
  for (int i = 0; i < N; i++) {
    dist[i] = INF;
  }
  dist[start] = 0;
  queue<int> que;
  que.push(start);

  while (!que.empty()) {
    int v = que.front();
    que.pop();
    for (int nv : G[v]) {
      if (dist[nv] != INF) continue;
      dist[nv] = dist[v] + 1;
      que.push(nv);
    }
  }
}

int main() {
  cin >> N;
  Graph G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  int root = 0;
  getdist(root, G);
  int id_max = -1;
  int v_max = -1;
  for (int i = 0; i < N; i++) {
    if (v_max < dist[i]) {
      v_max = dist[i];
      id_max = i;
    }
  }

  getdist(id_max, G);
  int v_max2 = -1;
  for (int i = 0; i < N; i++) {
    if (v_max2 < dist[i]) {
      v_max2 = dist[i];
    }
  }

  cout << v_max2 + 1 << endl;
}