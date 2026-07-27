#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(n) for (int i = 0; i < n; i++)

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--) {
        ll n,x;
        cin>>n>>x;
        vector<ll> a(n,0);
        f(n) cin >> a[i];
        ll v=0;
        f(n){
            if(a[i]%x==0 && a[i]>v){
                v=a[i];
            }
        }
        cout<<v<<endl;
    }
}