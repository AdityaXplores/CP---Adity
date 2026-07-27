#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &num : a) cin >> num;
    int maxs = 0;
    for(int i=1; i<n; i++) {
        maxs = max(maxs, a[i-1] - a[i]); 
    }
    for(int i=0; i<n-1; i++) {
        if(a[i] > a[i+1]) {
            a[i+1] += maxs;
        }
    }
    if(is_sorted(a.begin(), a.end())) {
        cout << "Yes" << "\n";
    }
    else {
        cout << "No" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--){
        solve();
    }
}