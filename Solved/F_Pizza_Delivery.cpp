/* Aditya Lahane */
#include<bits/stdc++.h>
using namespace std;

#define code ios_base::sync_with_stdio(false);
#define byy cin.tie(NULL);
#define Adity cout.tie(NULL);

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
using ll=long long;
using lld=long double;
using ull=unsigned long long;

const lld pi=3.1415926535;
const ll INF=1e18;
const ll mod=1e9+7;

typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
// stl containers
typedef pair<int,int> p;
typedef vector<int> vec;
typedef vector<p> vecp;
typedef unordered_map<int,int> um;
typedef map<int,int> m;

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define ff first
#define ss second
#define pb push_back
#define fr(i,st,end) for(int i=st;i<=end;i++)
#define frr(i,st,end) for(int i=st;i>=end;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define sz(x) ((int)(x).size());
#define all(x) (x).begin(), (x).end()

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

void solve(){
    ll n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;

    vector<pair<ll,ll>> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i].first;

    for(int i = 0; i < n; i++)
        cin >> a[i].second;

    sort(all(a));

    vector<ll> mn, mx;
    ll l = ax;

    for(auto [x, y] : a) {
        if(x > l) {
            mn.pb(y);
            mx.pb(y);
        }
        else {
            if(!mx.empty())  // safety check
                mx.back() = y;
        }
        l = x;
    }

    mn.pb(by);
    mx.pb(by);

    int s = mn.size();
    vector<vector<ll>> dp(s, vector<ll>(2));

    dp[0][0] = abs(ay - mx[0]) + abs(mx[0] - mn[0]);
    dp[0][1] = abs(ay - mn[0]) + abs(mx[0] - mn[0]);

    for(int i = 1; i < s; i++) {
        dp[i][0] = min(dp[i-1][0] + abs(mn[i-1] - mx[i]),
                       dp[i-1][1] + abs(mx[i-1] - mx[i]))
                       + abs(mx[i] - mn[i]);

        dp[i][1] = min(dp[i-1][0] + abs(mn[i-1] - mn[i]),
                       dp[i-1][1] + abs(mx[i-1] - mn[i]))
                       + abs(mx[i] - mn[i]);
    }

    ll ans = (bx - ax) + min(dp[s-1][0], dp[s-1][1]);
    cout << ans << "\n";
}

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

int32_t main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif

    code byy Adity

    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
