#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];

    vector<int> dp(n + 2, n);
    vector<int> next_pos_A(n + 2, n + 1);
    vector<int> next_pos_B(n + 2, n + 1);
    vector<int> first1_A(n + 2, n + 1);
    vector<int> first1_B(n + 2, n + 1);

    for (int i = n; i >= 1; --i) {
        if (a[i] == b[i]) {
            int k = a[i];
            int nA = next_pos_A[k + 1];
            int nB = next_pos_B[k + 1];
            if (nA != nB) {
                dp[i] = min(nA, nB) - 1;
            } else {
                dp[i] = dp[nA];
            }
        }
        next_pos_A[a[i]] = i;
        next_pos_B[b[i]] = i;
        first1_A[i] = next_pos_A[1];
        first1_B[i] = next_pos_B[1];
    }

    long long ans = 0;
    for (int L = 1; L <= n; ++L) {
        int nA = first1_A[L];
        int nB = first1_B[L];
        int max_R;
        if (nA != nB) {
            max_R = min(nA, nB) - 1;
        } else {
            max_R = dp[nA];
        }
        if (max_R >= L) {
            ans += (max_R - L + 1);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int multTestQ;
    if (cin >> multTestQ) {
        while (multTestQ--) {
            solve();
        }
    }
    return 0;
}