#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> color;
void dfs(Graph &G, int v, int cur = 0) {
  color[v] = cur;
  for (auto nv : G[v]) {
    if (color[nv] == -1) {
      dfs(G, nv, 1 - cur);
    }
  }
}

int main() {
  int N;
  cin >> N;
  Graph G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  color.assign(N, -1);
  for (int v = 0; v < N; ++v) {
    if (color[v] != -1) continue;
    dfs(G, v);
  }

  int n0 = 0, n1 = 0;
  for (int i = 0; i < N; i++) {
    if (color[i] == 0)
      n0++;
    else
      n1++;
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (n0 >= n1 && color[i] == 0 && cnt < N / 2) {
      cout << i + 1 << endl;
      cnt++;
    } else if (n1 > n0 && color[i] == 1 && cnt < N / 2) {
      cout << i + 1 << endl;
      cnt++;
    }
  }
}