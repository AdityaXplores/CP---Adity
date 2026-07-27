#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif

#define F first
#define S second
#define pb push_back
#define int long long

const long long INF = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int>a(n);
    for(auto &x:a)cin >> x;
    for(auto x:a){
        if(x==100){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int _ = 1;
    std::cin >> _;

    for(int i=1;i<=_;i++){
        debug(i);
        solve();
    }

}