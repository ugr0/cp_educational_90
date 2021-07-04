#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> data;

  UnionFind() = default;

  explicit UnionFind(size_t sz) : data(sz, -1) {}

  void init(int sz) { data.resize(sz, -1); }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  int find(int k) {
    if (data[k] < 0) return (k);
    return data[k] = find(data[k]);
  }

  int size(int k) { return -data[find(k)]; }

  bool same(int x, int y) { return find(x) == find(y); }
};

int H, W, Q;
UnionFind uf;
bool used[2010][2010];

void query1(int pi, int pj) {
  int di[4] = {-1, 1, 0, 0};
  int dj[4] = {0, 0, -1, 1};

  for (int i = 0; i < 4; i++) {
    int ni = pi + di[i], nj = pj + dj[i];
    if (ni < 0 || nj < 0 || ni >= H || nj >= W) continue;
    if (used[ni][nj] == false) continue;
    int hash1 = pi * W + pj;
    int hash2 = ni * W + nj;
    uf.unite(hash1, hash2);
  }

  used[pi][pj] = true;
}

bool query2(int pi, int pj, int qi, int qj) {
  if (used[pi][pj] == false || used[qi][qj] == false) return false;

  int hash1 = pi * W + pj;
  int hash2 = qi * W + qj;
  if (uf.same(hash1, hash2)) return true;

  return false;
}

void solve() {
  int t;
  cin >> t;
  if (t == 1) {
    int r, c;
    cin >> r >> c;
    --r, --c;
    query1(r, c);
  } else {
    int ra, ca, rb, cb;
    cin >> ra >> ca >> rb >> cb;
    --ra, --ca, --rb, --cb;
    if (query2(ra, ca, rb, cb)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}

int main() {
  cin >> H >> W;
  cin >> Q;
  uf.init(H * W);
  for (int i = 0; i < Q; i++) {
    solve();
  }
}