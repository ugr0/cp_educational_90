#include <bits/stdc++.h>
using namespace std;

long long N, Q;
vector<long long> A, B;

int main() {
  cin >> N;
  A.resize(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  cin >> Q;
  B.resize(Q);
  for (int i = 0; i < Q; i++) cin >> B[i];

  sort(A.begin(), A.end());
  for (int i = 0; i < Q; i++) {
    int j = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
    long long ret = abs(A[j] - B[i]);
    if (j > 0) {
      ret = min(ret, abs(A[j - 1] - B[i]));
    }
    cout << ret << endl;
  }
}