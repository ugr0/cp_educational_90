#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<long long>> a(H + 1, vector<long long>(W + 1));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
      a[i][W] += a[i][j];
      a[H][j] += a[i][j];
    }
  }

  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      int b = a[i][W] + a[H][j] - a[i][j];
      if (j == W - 1) {
        cout << b << endl;
      } else {
        cout << b << " ";
      }
    }
  }
}