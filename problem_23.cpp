#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, K;
  cin >> N >> K;
  vector<int> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
  }

  long long cnt = 0;

  for (int i = 0; i < N; i++) {
    cnt += abs(A[i] - B[i]);
  }

  long long d = K - cnt;
  if (cnt > K) {
    cout << "No" << endl;
  } else {
    if (d % 2 == 0)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
}