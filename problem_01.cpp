#include <bits/stdc++.h>
using namespace std;

long long N, L, K;
vector<long long> a;
bool f(long long x) {
  long long cnt = 0, pre = 0;
  for (int i = 0; i < N; i++) {
    if (a[i] - pre >= x && L - a[i] >= x) {
      cnt++;
      pre = a[i];
    }
  }

  // 最後の区間は満たすように数えているのでK以上でtrue
  if (K <= cnt) return true;  // xを増やせる
  return false;               // xを少なくする必要がある
}

int main() {
  cin >> N >> L;
  cin >> K;
  a.resize(N);
  for (int i = 0; i < N; i++) cin >> a[i];
  long long ng = L + 1, ok = -1;
  while (abs(ng - ok) > 1) {
    long long mid = (ok + ng) / 2;
    if (!f(mid))
      ng = mid;
    else
      ok = mid;
  }

  cout << ok << endl;
}