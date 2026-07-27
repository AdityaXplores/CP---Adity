#include "bits/stdc++.h"
using namespace std;

int solve(int n) {
    if(n == 0) return 0;
    return n / 5 + solve(n / 5);

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; 
    t = 1;
    int n; cin >> n;
    while(t--){
        cout << solve(n) << endl;
    }
}