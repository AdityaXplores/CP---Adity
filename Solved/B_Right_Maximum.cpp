#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;
using ll=long long;
using ull= unsigned long long;
using ld=long double;
using i128=__int128_t;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pld=pair<ld,ld>;
using pli=pair<ll,int>;
using pil=pair<int,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using vld=vector<ld>;
using vpii=vector<pii>;
using vpll=vector<pll>;
using vvi=vector<vi>;
using vvll=vector<vll>;
using vvld=vector<vld>;
#define FOR(i,a,b) for(int i=(a); i<(b); i++)
#define FORl(i,a,b) for(ll i=(a); i<(b); i++)
#define ROF(i,a,b) for(int i=(b)-1; i>=a; i--)
#define ROFl(i,a,b) for(ll i=(b)-1; i>=a; i--)
#define pb push_back
#define f first
#define sec second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define nl "\n"
ll MOD=998244353;
int N=1000005;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
vll fact,invfact, dearrange;
vi spf; vi primes; vvi divisors;
vector<bool> isPrime;

ll modpow(ll a, ll b, ll mod) {
    ll res=1; a%=mod;
    while (b) {
        if (b&1) res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll modinv(ll a, ll mod) {return modpow(a,mod-2,mod);}

ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}

struct DSU {
    vi par; DSU(int n){par.assign(n,-1);}
    int find(int i){if (par[i]<0) return i; return par[i]=find(par[i]);}
    int size(int i){return -par[(find(i))];}
    bool unite(int i,int j) {
        int rooti=find(i), rootj=find(j);
        if (rooti!=rootj) {
            par[rooti]+=par[rootj];
            par[rootj]=rooti;
            return true;
        }
        return false;

    }
};

void precompute_fact(int n, ll mod) {
    fact.resize(n+1); invfact.resize(n+1);
    fact[0]=1; invfact[0]=1;
    FORl(i,0,n) fact[i+1]=(fact[i]*(i+1LL))%mod;
    invfact[n]=modinv(fact[n],mod);
    ROFl(i,0,n) invfact[i]=(invfact[i+1]*(i+1LL))%mod;
}

ll nCr(ll n,ll r, ll mod) {
    if (r<0 || r>n) return 0;
    return fact[n]*invfact[r]%mod*invfact[n-r]%mod;
}

void precompute_dearrange(int n, ll mod) {
    dearrange.resize(n+1); dearrange[0]=1;
    dearrange[1]=0;
    FORl(i,2,n) dearrange[i]=(dearrange[i-1]+dearrange[i-2])*(i-1)%mod;
}

void seive_spf(int n) {
    spf.resize(n+1,0);
    iota(spf.begin(), spf.end(), 0);
    for (ll i=2; i*i<=n; ++i)
        if (spf[i]==i)
            for (ll j=i*i; j<n; j+= i)
                if (spf[j]==j) spf[j]=i;
}

void precompute_primes(int n) {
    primes.clear();
    isPrime.resize(n+1,true);
   for (ll i=2; i<=ll(n); i++)if (isPrime[i]) {
        for (ll j=i*i; j<=ll(n); j+=i) isPrime[j]=false;
    }
    isPrime[0]=isPrime[1]=false;
    FOR(i,2,n+1) if (isPrime[i]) primes.push_back(i);
}

void precompute_divisors(int n) {
    divisors.resize(n+1);
    FOR(i,1,n+1) divisors[i].clear();
    FOR(i,1,n+1) {
       for (int j=i; j<=n; j+=i) divisors[j].pb(i);
    }
}
map<int,int> prime_factorize(int n) {
    map<int,int> res;
    while (n>1) {
        res[spf[n]]++; n/=spf[n];
    }
    return res;
}
struct SegTree {
    vll tree; int n; SegTree(int size): n(size), tree(4*size,0){}
    void build(const vi &a, int v, int tl, int tr) {
        if (tl==tr) {tree[v]=a[tl]; return;}
        int tm=(tl+tr)>>1;
        build(a,v*2,tl,tm); build(a,v*2+1,tm+1,tr);
        tree[v]=(tree[v*2]+tree[v*2+1]);
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl==tr) {tree[v]+=val; return;}
        int tm=(tl+tr)>>1;
        if (pos<=tm) update(v*2,tl,tm,pos,val);
        else update(v*2+1,tm+1,tr,pos,val);
        tree[v]=tree[v*2]+tree[v*2+1];
    }
    ll query(int v, int tl, int tr, int l, int r) {
        if (l>r) return 0;
        if (l==tl && tr==r) return tree[v];
        int tm=(tl+tr)>>1;
        return query(v*2,tl,tm,l,min(r,tm))+query(v*2+1,tm+1,tr,max(l,tm+1),r);
    }
};

vll get_prime_factors(int n) {
    vll factors;
    while (n>1) {
        int p=spf[n];
        factors.pb(p);
        n/=p;
    }
    return factors;
}
vll get_divisors(ll x, ll k) {
    vll divs = {1};
    while (x>1) {
        ll p=spf[x],cnt=0;
        while(x%p==0) {x/=p; cnt++;}
        cnt*=k;
        ll sz=divs.size();
        ll mul=1;
        FOR(i,1,cnt+1){
            mul*=p;
            FOR(j,0,sz)divs.pb(divs[j] * mul);
        }
    }
    sort(all(divs));
    return divs;
}


ll multiply(ll a,ll b, ll mod) {
    return (__int128)a*b%mod;
}
bool check_prime(ll n) {
    for (ll i=2; i*i<=n; i++) if (n%i==0) return false;
    return true;
}

struct Mat {
    vvll a;
    Mat() {
        a.resize(2,vll(2,0));
    }
};

Mat mul(const Mat &A, const Mat &B) {
        Mat C;
            FOR(i,0,2) FOR(j,0,2) FOR(k,0,2) {
                C.a[i][j]=(C.a[i][j]+A.a[i][k]*B.a[k][j])%MOD;
            }

        return C;
    }

Mat power(Mat A,ll p) {
        Mat ans; FOR(i,0,2) ans.a[i][i]=1;
        while (p>0) {
            if (p&1) ans=mul(ans,A);
            A=mul(A,A); p/=2;
        }
        return ans;
}

ll nCr_large(ll n, int r) {
    if (r<0 || r>n) return 0;
    if (r==0) return 1;
    vll fact_r(r+1); fact_r[0]=1;
    FORl(i,1,r+1) fact_r[i]=(fact_r[i-1]*i)%MOD;
    ll num=1;
    FOR(i,0,r) num=(num*((n-i)%MOD+MOD)%MOD)%MOD;
    return (num*modinv(fact_r[r],MOD))%MOD;
}

ll nPr(ll n, ll r) {
    if (r<0||r>n) return 0;
    return (fact[n]*invfact[n-r])%MOD;
}

void print(i128 x) {
    if (x<0) {putchar('-'); x=-x; }
    if (x>9) print(x/10);
    putchar(x%10+'0');
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tc; cin>>tc;
    while (tc--){
       int n; cin>>n; vi a(n);
        FOR(i,0,n) cin>>a[i];
        int mx=0,ans=0;
        FOR(i,0,n) {
            if (mx<=a[i]){mx=a[i]; ans++;}
        }
        cout<<ans<<nl;
    }
}
