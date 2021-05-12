#include <bits/stdc++.h>
using namespace std;

int N;
string S;
long long dp[100100][8];
const long long mod = 1e9 + 7;

int main() {
  cin >> N;
  cin >> S;

  dp[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 8; j++) {
      dp[i + 1][j] += dp[i][j];
      if (S[i] == 'a' && j == 0) dp[i + 1][j + 1] += dp[i][j];
      if (S[i] == 't' && j == 1) dp[i + 1][j + 1] += dp[i][j];
      if (S[i] == 'c' && j == 2) dp[i + 1][j + 1] += dp[i][j];
      if (S[i] == 'o' && j == 3) dp[i + 1][j + 1] += dp[i][j];
      if (S[i] == 'd' && j == 4) dp[i + 1][j + 1] += dp[i][j];
      if (S[i] == 'e' && j == 5) dp[i + 1][j + 1] += dp[i][j];
      if (S[i] == 'r' && j == 6) dp[i + 1][j + 1] += dp[i][j];
    }

    for (int j = 0; j < 8; j++) dp[i + 1][j] %= mod;
  }

  cout << dp[N][7] << endl;
}