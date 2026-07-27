/* Aditya Lahane */
#include<bits/stdc++.h>
using namespace std;

#define code ios_base::sync_with_stdio(false);
#define by cin.tie(NULL);
#define Adity cout.tie(NULL);

#define int long long

using lld = long double;
using ull = unsigned long long;

const lld pi = 3.1415926535;
const int INF = 1e18;
const int mod = 1e9+7;

typedef pair<int,int> pll;
typedef vector<int> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<int,int> umll;
typedef map<int,int> mll;

/* STL containers */
typedef pair<int,int> p;
typedef vector<int> vec;
typedef vector<p> vecp;
typedef unordered_map<int,int> um;
typedef map<int,int> m;

#define ff first
#define ss second
#define pb push_back
#define qb pop_back
#define pf push_front
#define qf pop_front

#define fr(i,st,end) for(int i=st;i<=end;i++)
#define frr(i,st,end) for(int i=st;i>=end;i--)

#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";

#define maxe max_element
#define mine min_element

#define sor(x) sort((x).begin(), (x).end())
#define rsort(x) sort((x).begin(), (x).end(), greater<int>())

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

/* Operator overloads */

template<typename T1, typename T2>
istream& operator>>(istream &istream, pair<T1, T2> &p){
    return (istream >> p.first >> p.second);
}

template<typename T>
istream& operator>>(istream &istream, vector<T> &v){
    for(auto &it : v) cin >> it;
    return istream;
}

template<typename T1, typename T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p){
    return (ostream << p.first << " " << p.second);
}

template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &c){
    for(auto &it : c) cout << it << " ";
    return ostream;
}

/* Math utilities */

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a/gcd(a,b))*b;
}

int modMul(int a,int b,int mod){
    int res=0;
    a%=mod;
    while(b){
        if(b&1) res=(res+a)%mod;
        a=(a+a)%mod;
        b>>=1;
    }
    return res;
}

int powermod(int x,int y,int p){
    int res=1;
    x%=p;
    while(y>0){
        if(y&1) res=(res*x)%p;
        y>>=1;
        x=(x*x)%p;
    }
    return res;
}

bool isPrime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0||n%3==0) return false;
    for(int i=5;i*i<=n;i+=6)
        if(n%i==0||n%(i+2)==0)
            return false;
    return true;
}

bool isPowerOfTwo(int n){
    if(n==0) return false;
    return (ceil(log2(n))==floor(log2(n)));
}

int numberOfDigits(int n){
    return floor(log10(n))+1;
}

bool isPerfectSquare(int x){
    if(x>=0){
        int sr=sqrt(x);
        return sr*sr==x;
    }
    return false;
}

/* Debug section */

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

void _print(int t){cerr<<t;}
void _print(string t){cerr<<t;}
void _print(char t){cerr<<t;}
void _print(lld t){cerr<<t;}
void _print(double t){cerr<<t;}
void _print(ull t){cerr<<t;}

template<class T,class V> void _print(pair<T,V> p);
template<class T> void _print(vector<T> v);
template<class T> void _print(set<T> v);
template<class T,class V> void _print(map<T,V> v);
template<class T> void _print(multiset<T> v);

template<class T,class V>
void _print(pair<T,V> p){
    cerr<<"{";
    _print(p.ff);
    cerr<<",";
    _print(p.ss);
    cerr<<"}";
}

template<class T>
void _print(vector<T> v){
    cerr<<"[ ";
    for(T i:v){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}

template<class T>
void _print(set<T> v){
    cerr<<"[ ";
    for(T i:v){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}

template<class T>
void _print(multiset<T> v){
    cerr<<"[ ";
    for(T i:v){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}

template<class T,class V>
void _print(map<T,V> v){
    cerr<<"[ ";
    for(auto i:v){
        _print(i);
        cerr<<" ";
    }
    cerr<<"]";
}

/* Binary search helpers */

int LB(vector<int>&arr,int key){
    auto lower=lower_bound(arr.begin(),arr.end(),key);
    if(lower!=arr.end()) return lower-arr.begin();
    return -1;
}

int UB(vector<int>&arr,int key){
    auto upper=upper_bound(arr.begin(),arr.end(),key);
    if(upper!=arr.end()) return upper-arr.begin();
    return -1;
}

/* Prefix Suffix */

vector<int> buildPrefix(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n+1,0);
    for(int i=1;i<=n;i++)
        ans[i]=ans[i-1]+arr[i-1];
    return ans;
}

vector<int> buildSuffix(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n+1,0);
    for(int i=n-1;i>=0;i--)
        ans[i]=ans[i+1]+arr[i];
    return ans;
}

/* Solve */

void solve(){

    int n,m,k;
    cin>>n>>m>>k;

    vector<int>a(n),b(m);
    cin>>a>>b;

    vector<int>fa(n+1,0),fb(m+1,0);

    int c=0;
    for(int i=0;i<n;i++){
        if(a[i]==1){
            c++;
            fa[c]++;
        }
        else c=0;
    }

    c=0;
    for(int i=0;i<m;i++){
        if(b[i]==1){
            c++;
            fb[c]++;
        }
        else c=0;
    }

    for(int i=n-1;i>0;i--)
        fa[i]+=fa[i+1];

    for(int i=m-1;i>0;i--)
        fb[i]+=fb[i+1];

    int ans=0;

    for(int i=1;i*i<=k;i++){
        if(k%i==0){

            int j=k/i;

            if(i<=n && j<=m)
                ans+=fa[i]*fb[j];

            if(i!=j && j<=n && i<=m)
                ans+=fa[j]*fb[i];
        }
    }

    cout<<ans<<"\n";
}

/* Main */

int32_t main(){

#ifndef ONLINE_JUDGE
freopen("Error.txt","w",stderr);
#endif

code by Adity

int t=1;

while(t--)
solve();

return 0;
}