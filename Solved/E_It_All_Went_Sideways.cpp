#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> v(n);
        ll sum = 0;
        for(auto &it : v) {
            cin >> it;
            sum += it;
        }
        vector<ll> suf_mn(n);
        suf_mn[n - 1] = v[n - 1];
        sum -= suf_mn[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suf_mn[i] = min(suf_mn[i + 1], v[i]);
            sum -= suf_mn[i];
        }

        ll mx = -1, cur = 1;
        for(int i = 1; i < n; i++) {
            if(suf_mn[i] == suf_mn[i - 1]) cur++;
            else {
                mx = max(mx, cur);
                cur = 1;
            }
        }

        mx = max(mx, cur);
        cout << sum + mx - 1 << endl;
    }
}