#include <bits/stdc++.h>
using namespace std;

using ll = long long;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if(n <= 3) cout << n << "\n";
        else cout << n % 2 << "\n"; 
    }
    return 0;
}
