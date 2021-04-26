#include <bits/stdc++.h>
using namespace std;

string S;
int N;
int K;
int pos[100010][30];

int main() {
  cin >> N;
  cin >> K;
  cin >> S;

  for (int i = 0; i < 26; i++) pos[S.size()][i] = S.size();
  for (int i = (int)S.size() - 1; i >= 0; --i) {
    for (int j = 0; j < 26; j++) {
      if ((int)(S[i] - 'a') == j) {
        pos[i][j] = i;
      } else {
        pos[i][j] = pos[i + 1][j];
      }
    }
  }

  string ans = "";
  int now = 0;
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < 26; j++) {
      int next = pos[now][j];
      int max_length = (int)(S.size() - next) + i;
      if (max_length >= K) {
        ans += (char)('a' + j);
        now = next + 1;
        break;
      }
    }
  }

  cout << ans << endl;
}