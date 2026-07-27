#include <bits/stdc++.h>
//using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 
#endif

#define F first
#define S second
#define pb push_back
//#define int long long

const long long INF = 1e18;

void solve() {
    std::string s;
    std::cin >> s;
    int n = s.size();
    // std::vector<int>cnt(2);
    // for(auto c:s)cnt[c-'a']++;
    // if(n&1){
    //     if(abs(cnt[1]-cnt[0])!=1){
    //         std::cout << "NO\n";
    //         return;
    //     }
    // }
    // else{
    //     if(cnt[1]!=cnt[0]){
    //         std::cout << "NO\n";
    //         return;
    //     }
    // }
    int c = 1;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1])c++;
    }
    if(c>3)std::cout << "NO\n";
    else std::cout << "YES\n";
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