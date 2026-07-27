#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    int64_t mn = 0;
    int64_t mx = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      mn += a;
      mx += a;
      mx = max(mx, abs(mn));
      mx = max(mx, abs(mx));
    }
    cout << mx << '\n';
  }
  return 0;
}