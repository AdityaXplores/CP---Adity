#include <bits/stdc++.h>
using namespace std;

long long solve(long long n) {
    if (n == 0) return 0;

    long long x = log2(n);        // msb position
    long long p = 1LL << x;       // 2^x

    long long bitsTill = x * (p >> 1);      // x * 2^(x-1)
    long long msbBits = n - p + 1;

    return bitsTill + msbBits + solve(n - p);
}

int main() {
    long long n;
    cin >> n;

    cout << solve(n) << endl;
}