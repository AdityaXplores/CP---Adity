//ADITYA LAHANE
#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct DSU {
    vector<int> p, r;
    DSU(int n) {
        p.resize(n + 1);
        r.assign(n + 1, 0);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x) {
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;
        if (r[a] < r[b]) swap(a, b);
        p[b] = a;
        if (r[a] == r[b]) r[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<ll, pair<int, int>>> e(m);

    for (int i = 0; i < m; i++) cin >> e[i].second.first >> e[i].second.second >> e[i].first;
    sort(e.begin(), e.end());
    DSU d(n);
    ll ans = 0;
    int cnt = 0;
    for(auto &x : e) {
        if(d.unite(x.second.first, x.second.second)){
            ans += x.first;
            cnt++;
        }
    }
    if(cnt != n - 1) cout << -1 << '\n';
    else cout << ans << '\n';
return 0;
}
