#include <bits/stdc++.h>
#include <climits>
using namespace std;

int a[200005];
map<int, int> mp;
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+1+n);
    swap(a[1], a[n]);
    sort(a+2, a+n+1);
    vector<int> v1, v2;
    for(int i=2; i<=n; i++){
        if(v1.size() && v1.back() == a[i]) v2.push_back(a[i]);
        else v1.push_back(a[i]);
    }
    int t = 1;
    for(int i=0; i<v1.size(); i++) a[++t] = v1[i];
    for(int i=0; i<v2.size(); i++) a[++t] = v2[i];

    long long ans = 0;
    mp.clear();
    int nw = 0, mx = 0;
    for(int i=1; i<=n; i++){
        mp[a[i]]++;
        mx = max(mx, a[i]);
        while (mp[nw]) ++nw;
			ans += mx + nw;
    }
    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t; cin >>t;
    while(t--) solve();
}