#include <bits/stdc++.h>
using namespace std;

/*================ FAST IO =================*/
#define code ios::sync_with_stdio(false);
#define by cin.tie(NULL);
#define Adity cout.tie(NULL);

/*================ TYPES =================*/
using ll = long long;
using lld = long double;
using ull = unsigned long long;

const lld pi = 3.141592653589793;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<int> vec;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;

/*================ SHORTCUTS =================*/
#define ff first
#define ss second
#define pb push_back
#define cut pop_back
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define frr(i,a,b) for(int i=a;i>=b;i--)
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define pm cout<<"-1\n"
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

/*================ SAFE SORT MACROS =================*/
#define sortv(x) sort((x).begin(), (x).end())
#define rsortv(x) sort((x).begin(), (x).end(), greater<int>())

/*================ INPUT / OUTPUT OVERLOAD =================*/
template<typename T1, typename T2>
istream& operator>>(istream &in, pair<T1,T2> &p){ in>>p.first>>p.second; return in; }

template<typename T>
istream& operator>>(istream &in, vector<T> &v){ for(auto &x:v) in>>x; return in; }

template<typename T1, typename T2>
ostream& operator<<(ostream &out, const pair<T1,T2> &p){ out<<p.first<<" "<<p.second; return out; }

template<typename T>
ostream& operator<<(ostream &out, const vector<T> &v){ for(auto &x:v) out<<x<<" "; return out; }

/*================ MATH =================*/
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b){ return a/gcd(a,b)*b; }

ll modMul(ll a,ll b,ll m){
    ll res=0; a%=m;
    while(b){
        if(b&1) res=(res+a)%m;
        a=(a+a)%m;
        b>>=1;
    }
    return res;
}

ll powerMod(ll x,ll y,ll p){
    ll res=1; x%=p;
    while(y){
        if(y&1) res=(res*x)%p;
        x=(x*x)%p;
        y>>=1;
    }
    return res;
}

bool isPrime(ll n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0||n%3==0) return false;
    for(ll i=5;i*i<=n;i+=6)
        if(n%i==0||n%(i+2)==0) return false;
    return true;
}

bool isPowerOfTwo(ll n){
    return n>0 && (n&(n-1))==0;
}

bool isPerfectSquare(ll x){
    if(x<0) return false;
    ll s=sqrt(x);
    return s*s==x;
}

/*================ DEBUG =================*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" = "; _print(x); cerr<<"\n";
#else
#define debug(x)
#endif

void _print(ll x){cerr<<x;}
void _print(int x){cerr<<x;}
void _print(string x){cerr<<x;}
void _print(char x){cerr<<x;}
void _print(lld x){cerr<<x;}
void _print(double x){cerr<<x;}
void _print(ull x){cerr<<x;}

template<class T,class V> void _print(pair<T,V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> v);
template<class T,class V> void _print(map<T,V> v);

template<class T,class V> void _print(pair<T,V> p){ cerr<<"{"; _print(p.ff); cerr<<","; _print(p.ss); cerr<<"}"; }
template<class T> void _print(vector<T> v){ cerr<<"[ "; for(auto i:v){_print(i); cerr<<" ";} cerr<<"]"; }
template<class T> void _print(set<T> v){ cerr<<"[ "; for(auto i:v){_print(i); cerr<<" ";} cerr<<"]"; }
template<class T,class V> void _print(map<T,V> v){ cerr<<"[ "; for(auto i:v){_print(i); cerr<<" ";} cerr<<"]"; }

/*================ BINARY SEARCH =================*/
int LB(const vector<ll>& arr,ll key){
    auto it=lower_bound(arr.begin(),arr.end(),key);
    return (it==arr.end()?-1:it-arr.begin());
}

int UB(const vector<ll>& arr,ll key){
    auto it=upper_bound(arr.begin(),arr.end(),key);
    return (it==arr.end()?-1:it-arr.begin());
}

/*================ PREFIX / SUFFIX =================*/
vector<ll> buildPrefix(const vector<ll>& arr){
    int n=arr.size();
    vector<ll> pref(n);
    pref[0]=arr[0];
    for(int i=1;i<n;i++) pref[i]=pref[i-1]+arr[i];
    return pref;
}

vector<ll> buildSuffix(const vector<ll>& arr){
    int n=arr.size();
    vector<ll> suf(n);
    suf[n-1]=arr[n-1];
    for(int i=n-2;i>=0;i--) suf[i]=suf[i+1]+arr[i];
    return suf;
}

/*================ PROBLEM LOGIC =================*/
ll solve(ll x){
    return x*(x+1)/2;
}

/*================ MAIN =================*/
int main(){
#ifndef ONLINE_JUDGE
    freopen("Error.txt","w",stderr);
#endif
    code by Adity

    int t; 
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        if(l>r) swap(l,r);
        cout<<solve(r)-solve(l-1)<<"\n";
    }
    return 0;
}