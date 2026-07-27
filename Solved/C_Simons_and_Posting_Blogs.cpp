#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;

    vector<vector<int>> a(n);

    for (int i = 0; i < n; i++) {
        int l; cin >> l;

        a[i].resize(l);
        for (int _ = 0; _ < l; _++) {
            cin >> a[i][_];
        }

        reverse(a[i].begin(), a[i].end());

        vector<int> b;

        for (auto x : a[i]) {
            if (find(b.begin(), b.end(), x) == b.end()) {
                b.push_back(x);
            }
        }
        a[i] = b;
    }

    vector<int> vis(n);

    vector<int> ans;

    for (int _ = 0; _ < n; _++) {
        int t = -1;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && (t == -1 || a[i] < a[t])) {
                t = i;
            }
        }
        vis[t] = 1;
        for (auto x : a[t]) {
            ans.push_back(x);
            
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    auto it = std::find(a[i].begin(), a[i].end(), x);
                    if (it != a[i].end()) {
                        a[i].erase(it);
                    }
                }
            }
        }
    }
    for (auto x : ans) {
        std::cout << x << " \n"[x == ans.back()];
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int t; cin >> t;

    while (t--) {
        solve();
    }
}