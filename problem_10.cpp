#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> c1(N + 2), c2(N + 2);
  for (int i = 0; i < N; i++) {
    int C, P;
    cin >> C >> P;
    if (C == 1)
      c1[i] = P;
    else
      c2[i] = P;
  }

  for (int i = 0; i < N; i++) {
    c1[i + 1] += c1[i];
    c2[i + 1] += c2[i];
  }

  int Q;
  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int L, R;
    cin >> L >> R;
    L--, R--;
    int ans1 = c1[R];
    int ans2 = c2[R];
    if (L >= 0) {
      ans1 -= c1[L - 1];
      ans2 -= c2[L - 1];
    }

    cout << ans1 << " " << ans2 << endl;
  }
}