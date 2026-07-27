#include "bits/stdc++.h"
using namespace std;

string solve(int x, int y) {
    if ((2 * x - y) % 3 || (2 * x - y) < 0
        || (2 * y - x) % 3 || (2 * y - x) < 0)
        return "NO\n";
    return "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    vector<pair<int, int>> q(t+1);
    while(t--){
        cin >> q[t].first >> q[t].second;
        cout << solve(q[t].first, q[t].second) << endl;
    }
}