#include <bits/stdc++.h>
using namespace std;
struct ftree{
    int n;
    vector<long long> ft;

    ftree(int n){
        this->n = n;
        ft.assign(n+1,0);
    }

    void update(int i, int val){
        while(i <= n){
            ft[i] += val;
            i += (i&-i);
        }
    }

    long long query(int r){
        long long sum = 0;
        while(r){
            sum += ft[r];
            r -= (r&-r);
        }
        return sum;
    }

    long long query(int l, int r){
        return query(r) - query(l-1);
    }
};