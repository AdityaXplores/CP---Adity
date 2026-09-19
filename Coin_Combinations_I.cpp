#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int main() {
    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for(int &coin : coins){
        cin >> coin;
    }

    vector<int> dp(x + 1, 0);
    dp[0] = 1;
    sort(coins.begin(), coins.end());
    for(int i = 1; i<= x; i++){
        for(int coin : coins){
            if(coin > i){
                break;
            }
            dp[i] = (dp[i] + dp[i - coin]);

            if(dp[i] >= mod){
                dp[i] -= mod;
            }

        }
    }   
    cout << dp[x] << '\n';
}
// c

// i - c

// dp[i-c]

// dp[i] += dp[i-c]

// for(coin : coins){
//     for(sum = coin; sum <= x; sum++)
// }


// or

// for(sum = 1; sum <= x; sum++){
//     for(coin : coins)
// }


// coins = {2, 3} and x =5;

// 2 +3 
// 3 + 2


// dp[0] = 1;

// dp[2] = dp[0] = 1

// dp[3] = dp[0] = 1

// 5 - 2 = 3

// 2