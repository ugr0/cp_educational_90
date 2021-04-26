#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
long long dp[10007][33];

// case: N<=10000 and B<=30
// O(NBK)

int main() {
  long long N, B, K;
  cin >> N >> B >> K;

  vector<int> c(K);
  for (int i = 0; i < K; i++) cin >> c[i];

  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < B; j++) {
      for (int k = 0; k < K; k++) {
        int nex = (10 * j + c[k]) % B;
        dp[i + 1][nex] += dp[i][j];
        dp[i + 1][nex] %= mod;
      }
    }
  }

  cout << dp[N][0] << endl;
  return 0;
}