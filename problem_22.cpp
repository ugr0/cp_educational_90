#include <bits/stdc++.h>
using namespace std;

long long GCD(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return GCD(b, a % b);
}

long long cut(long long a, long long b) {
  if (a == b) {
    return 0LL;
  } else {
    return a / b - 1;
  }
}

int main() {
  long long A, B, C;
  cin >> A >> B >> C;

  long long n = GCD(GCD(A, B), C);
  long long ans = cut(A, n) + cut(B, n) + cut(C, n);
  cout << ans << endl;
}