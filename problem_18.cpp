#include <bits/stdc++.h>
using namespace std;

int main() {
  double T, L, X, Y;
  cin >> T >> L >> X >> Y;
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; i++) {
    double E;
    cin >> E;

    // 観覧車のパラメータ
    double x = 0;
    double y = -(L / 2.0) * sin(E / T * 2 * M_PI);
    double z = L / 2.0 - (L / 2.0) * cos(E / T * 2 * M_PI);

    double A = sqrt(X * X + (Y - y) * (Y - y));  // 水平
    double B = z;                                // 高さ

    double ans = atan2(B, A) * 180 / M_PI;
    cout << setprecision(20) << ans << endl;
  }
}