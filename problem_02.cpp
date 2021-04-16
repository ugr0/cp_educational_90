#include <bits/stdc++.h>
using namespace std;

int N;

void dfs(string s, int now, int sum) {
  if (s.size() == N) {
    cout << s << endl;
    return;
  }
  int close = N - now;
  int open = N / 2 - now;
  if (open && sum < N / 2) {
    dfs(s + '(', now + 1, sum + 1);
  }
  if (now > 0) dfs(s + ')', now - 1, sum);

  return;
}

int main() {
  cin >> N;
  if (N % 2 != 0) return 0;

  dfs("(", 1, 1);
}