#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int mod = 1e9 + 7;

    vector<int> dp(n+1);

    dp[0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j < 7; j++){
            if(j <= i){
                dp[i] = (dp[i] + dp[i-j]) % mod;
            }
        }
    }
    cout << dp[n] << endl;
}

