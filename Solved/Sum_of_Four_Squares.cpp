#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
const int MAXN = 200005; 
pair<int, int> sum_map[MAXN + 1];
bool has_sum[MAXN + 1];

void precompute() {
    for (int a = 0; a * a <= MAXN; ++a) {
        for (int b = a; a * a + b * b <= MAXN; ++b) {
            int current_sum = a * a + b * b;
            if (!has_sum[current_sum]) {
                has_sum[current_sum] = true;
                sum_map[current_sum] = {a, b};
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    
    for (int c = 0; c * c <= n; ++c) {
        for (int d = c; c * c + d * d <= n; ++d) {
            int remaining = n - c * c - d * d;
            if (remaining >= 0 && has_sum[remaining]) {
                pair<int, int> p = sum_map[remaining];
                cout << p.first << " " << p.second << " " << c << " " << d << "\n";
                return;
            }
        }
    }
    cout << "No solution found.\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precompute();
    
    int t; 
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
