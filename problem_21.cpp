#include <bits/stdc++.h>
using namespace std;

using Graph = vector<vector<int>>;

int N, M;
Graph G1(1 << 18);
Graph G2(1 << 18);
vector<int> I;
bool used[1 << 18];
long long cnt = 0;

void dfs1(int v) {
  used[v] = true;
  for (auto nv : G1[v]) {
    if (used[nv] == false) dfs1(nv);
  }
  // 帰りがけ順に保存
  I.push_back(v);
}

void dfs2(int v) {
  used[v] = true;
  cnt++;
  for (auto nv : G2[v]) {
    if (used[nv] == false) dfs2(nv);
  }
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    G1[A].push_back(B);  // 1回目用のグラフ
    G2[B].push_back(A);  // 2回目でSCCをする用のグラフ
  }

  // dfs1
  for (int i = 0; i < N; i++) {
    if (used[i] == false) dfs1(i);
  }

  // dfs2
  long long ans = 0;
  reverse(I.begin(), I.end());
  for (int i = 0; i < N; i++) used[i] = false;
  for (int i : I) {
    if (used[i] == true) continue;
    cnt = 0;
    dfs2(i);
    ans += cnt * (cnt - 1LL) / 2LL;
  }

  cout << ans << endl;
}