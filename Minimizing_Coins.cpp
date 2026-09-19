#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x; 
    cin >> n >> x;

    vector<int> coins(n);

    for(int &coin : coins){
        cin >> coin;
    }

    vector<int> dp(x + 1, x + 1);

    dp[0] = 0;

    for(int i = 1; i <= x; i++){
        for(int coin : coins){
            if(i - coin >= 0){
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    if(dp[x] == x + 1){
        cout << -1 << '\n';
    } else {
        cout << dp[x] << '\n';
    }
}

// coins = {1, 3, 4} and x = 6

// rem = 2
// 1 + 1
// rem = 0;
// 4, 1, 1

// 3 + 3

// dp[i]

// dp[0] = 0;

// dp[i]
// c
// i - c

// dp[i-c]

// dp[i-c] + 1



// coins = {1, 5, 7} and x = 11;

// dp[1] = dp[0] + 1 = 1;

// dp[2] = dp[1] + 1= 2;

// dp[5] = dp[0] + 1 = 1
// dp[6] = 2;
// dp[10] = 2
// dp[11] = 3;



// {5, 7} and x = 3
// INT_MAX;
// x + 1
