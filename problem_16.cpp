#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int main() {
  long long N, A, B, C;
  cin >> N >> A >> B >> C;

  long long ans = INF;
  for (int a = 0; a < 10000; a++) {
    for (int b = 0; b < 10000; b++) {
      long long sum = A * a + B * b;
      if (sum > N) continue;
      long long diff = N - sum;
      if (diff % C != 0) continue;
      ans = min(ans, a + b + diff / C);
    }
  }

  cout << ans << endl;
}