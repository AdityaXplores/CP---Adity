#include<bits/stdc++.h>
using namespace std;

#define ll long long

long long recur(vector<long long>& v, vector<long long>& dp, long long idx);

void adity(){
    ll n;
    cin >> n;

    vector<ll> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    vector<ll> dp(n+1, -1);
    dp[0] = 0;

    for(int i = 1; i <= n; i++){
        recur(v, dp, i);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i]);
    }

    cout << ans << "\n";
}

long long recur(vector<long long>& v, vector<long long>& dp, long long idx){
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];

    ll ans = 0;

    for(ll i = 1; i * i <= idx; i++){
        if(idx % i == 0){
            ll f1 = i;
            ll f2 = idx / i;

            if(f1 != idx && v[idx] > v[f1])
                ans = max(ans, recur(v, dp, f1));

            if(f2 != idx && f2 != f1 && v[idx] > v[f2])
                ans = max(ans, recur(v, dp, f2));
        }
    }

    return dp[idx] = ans + 1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        adity();
    }
}
