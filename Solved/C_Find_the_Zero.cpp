#include <bits/stdc++.h>
using namespace std;
int n;
int query(int i , int j) {
    cout << "? " << i << " " << j << endl;
    int x;
    cin >> x; 
    return x;
}
 
void solve() {
    cin >> n;
    for(int i=4;i<2*n;i+=2) {
        int ans = query(i , i + 1);
        if (ans == 1) {
            cout << "! " << i << endl;
            return; 
        }
    }
 
    if (query(1, 2)) {
        cout << "! " << 1 << endl;
        return;
    }
 
    if (query(2, 3)) {
        cout << "! " << 2 << endl;
        return;
    }
 
    if (query(1 , 3)) {
        cout << "! " << 1 << endl;
        return;
    }
 
    cout << "! " << 2 * n << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
 
    return 0;
}