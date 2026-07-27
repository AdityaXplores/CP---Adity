#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

int n;
int a[N];
int seg[4 * N];

void build(int ind, int low, int hi){
    if(low == hi){
        seg[ind] = a[low];
        return;
    }

    int mid = (low + hi) >> 1;

    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, hi);

    seg[ind] = max(seg[2*ind+1], seg[2*ind+2]);
}

int query(int ind, int low, int hi, int l, int r){

    // complete overlap
    if(low >= l && hi <= r)
        return seg[ind];

    // no overlap
    if(hi < l || low > r)
        return INT_MIN;

    int mid = (low + hi) >> 1;

    int left = query(2*ind+1, low, mid, l, r);
    int right = query(2*ind+2, mid+1, hi, l, r);

    return max(left, right);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    build(0, 0, n-1);

    int q;
    cin >> q;

    while(q--){
        int l, r;
        cin >> l >> r;

        cout << query(0, 0, n-1, l, r) << "\n";
    }
}