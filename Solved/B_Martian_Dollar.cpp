#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(); cin.tie(nullptr);

    int n, b;   cin >> n >> b;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    int maxx = b;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int dollars = b / p[i];
            int leftover = b % p[i];
            
            int curr_money = leftover + (dollars * p[j]);
            
            maxx = max(maxx, curr_money);
        }
    }
    
    cout << maxx << endl;

}