#include<bits/stdc++.h>
using namespace std;
#define int long long
#define nl "\n"

mt19937_64 randll(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> mrk(n + 1);
    int res = 0, cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (mrk[i]) cnt--;
        mrk[a[i]] = 1;
        cnt++;
        res = max(res, cnt);
    }
    cout << res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        cout << nl;
    }
}