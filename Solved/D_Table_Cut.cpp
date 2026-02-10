//ADITYA LAHANE
#include<bits/stdc++.h>
using namespace std;
#define code ios_base::sync_with_stdio(false);
#define by cin.tie(NULL);
#define Adity cout.tie(NULL);
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
using ll=long long;
using lld=long double;
using ull=unsigned long long;
const lld pi=3.1415926535;
const ll INF=1e18;
const ll mod=1e9+7;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<string> vs;
typedef unordered_map<ll,ll> umll;
typedef map<ll,ll> mll;
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//stl containers
typedef pair<int,int> p;
typedef vector<int> vec;
typedef vector<p> vecp;
typedef vector<string> vs;
typedef unordered_map<int,int> um;
typedef map<int,int> m;
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define ff first
#define ss second
#define pb push_back
#define cut pop_back
#define fr(i,st,end) for(int i=st;i<=end;i++)
#define frr(i,st,end) for(int i=st;i>=end;i--)
#define py cout<<"YES\n";
#define pm cout<<"-1\n";
#define pn cout<<"NO\n";
#define sort(x) sort(x.begin(),x.end());
#define rsort(x) sort(x.begin(),x.end(),greater<int>());
#define sz(x) ((int)(x).size());
#define all(x) (x).begin(), (x).end()
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//operators overloads
template<typename T1, typename T2> // cin >> pair<T1, T2>
istream& operator>>(istream &istream, pair<T1, T2> &p) { return (istream >> p.first >> p.second); }
template<typename T> // cin >> vector<T>
istream& operator>>(istream &istream, vector<T> &v){for (auto &it : v) cin >> it;return istream;}
template<typename T1, typename T2> // cout << pair<T1, T2>
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) { return (ostream << p.first << " " << p.second); }
template<typename T> // cout << vector<T>
ostream& operator<<(ostream &ostream, const vector<T> &c) { for (auto &it : c) cout << it << " "; return ostream; }
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
ll modMul(ll a,ll b,ll mod){ll res = 0;a %= mod;while (b){if (b & 1)res = (res + a) % mod;b >>= 1;}return res;}
ll powermod(ll x, ll y, ll p){ll res = 1;x = x % p;if (x == 0) return 0;while (y > 0){if (y & 1)res = (res*x) % p;y = y>>1;x = (x*x) % p;}return res;}
bool isPrime(ll n){if(n<=1)return false;if(n<=3)return true;if(n%2==0||n%3==0)return false;for(int i=5;i*i<=n;i=i+6)if(n%i==0||n%(i+2)==0)return false;return true;}
bool isPowerOfTwo(int n){if(n==0)return false;return (ceil(log2(n)) == floor(log2(n)));}
ll numberOfDigits(ll n){return floor(log10(n)) + 1;}
bool isPerfectSquare(ll x){if (x >= 0) {ll sr = sqrt(x);return (sr * sr == x);}return false;}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//binary search section
int LB(vector<ll>arr,ll key){auto lower = lower_bound(arr.begin(), arr.end(), key); if (lower != arr.end()) {return lower - arr.begin(); } return -1; }
int UB(vector<ll>arr,ll key){auto upper = upper_bound(arr.begin(), arr.end(), key);if (upper != arr.begin()&&(upper-arr.begin())<arr.size()) {return upper - arr.begin();}return -1;}
bool checkerFunction(int x,vector<int>&arr){return true;}
int BSAns(int st,int end,vector<int>arr){int ans=-1;while(st<=end){int mid=st+(end-st)/2;if(checkerFunction(mid,arr)){ }else{}}return ans;}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//prefix suffix section 1 based
vector<int> buildPrefix(vector<int>&arr){vector<int>ans(arr.size(),0);for(int i=1;i<=arr.size();i++){ans[i]=arr[i]+ans[i-1];}return ans;}
vector<int> buildSuffix(vector<int>&arr){vector<int>ans(arr.size()+1,0);for(int i=arr.size()-1;i>=1;i--){ans[i]=ans[i+1]+arr[i];}return ans;}
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
//1)Try Sample Test Cases
//2)Dry run on Each Sample Test Case
//3)Try Extreme test cases min and max
//A)Brute Force B)Math with optimization C) Math with implemention

void solve(){
    //code here
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
    #endif
    code by Adity
    int t; cin >> t;
    while(t--){
        solve();
    }
return 0;
}











































#pragma GCC optimize("O3")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

// Maximum possible sum of ones is 300,000.
// We use a safe upper bound.
const int MAX_SUM = 300005;
typedef bitset<MAX_SUM> BitSet;

int N, M;
vector<vector<int>> row_pref;
vector<int> cut_col; // Stores the column index of the cut for each row
bool is_transposed = false;

// Helper to get sum of ones in grid[r][0...k-1]
inline int get_ones(int r, int k) {
    return row_pref[r][k];
}

// Recursive function to reconstruct the path
void solve_recursive(int r1, int c1, int r2, int c2, int target) {
    // Base case: Single row processing
    if (r1 == r2 - 1) {
        for (int k = c1; k <= c2; ++k) {
            if (get_ones(r1, k) == target) {
                cut_col[r1] = k;
                return;
            }
        }
        return;
    }

    int mid = r1 + (r2 - r1) / 2;
    int cols = c2 - c1 + 1;

    // --- Forward DP: from r1 to mid ---
    // fwd[k] stores bitset of reachable sums ending at row (mid-1) with cut at column (c1 + k)
    // Sums are relative to the start of r1.
    vector<BitSet> fwd(cols);
    
    // Initialize first row (r1)
    for (int k = 0; k < cols; ++k) {
        fwd[k].set(get_ones(r1, c1 + k));
    }

    for (int i = r1 + 1; i < mid; ++i) {
        vector<BitSet> next_fwd(cols);
        BitSet pref; // Accumulates union of fwd[0...k]
        for (int k = 0; k < cols; ++k) {
            pref |= fwd[k];
            // Transition: previous cut <= k, add current row ones
            next_fwd[k] = pref << get_ones(i, c1 + k);
        }
        fwd = move(next_fwd);
    }

    // --- Backward DP: from r2 to mid ---
    // bwd[k] stores bitset of reachable sums for the bottom part starting at row mid with cut at (c1 + k)
    vector<BitSet> bwd(cols);
    
    // Initialize last row (r2-1)
    for (int k = 0; k < cols; ++k) {
        bwd[k].set(get_ones(r2 - 1, c1 + k));
    }

    for (int i = r2 - 2; i >= mid; --i) {
        vector<BitSet> next_bwd(cols);
        BitSet suff; // Accumulates union of bwd[k...cols-1]
        for (int k = cols - 1; k >= 0; --k) {
            suff |= bwd[k];
            // Transition: next cut >= k, add current row ones
            next_bwd[k] = suff << get_ones(i, c1 + k);
        }
        bwd = move(next_bwd);
    }

    // --- Merge Step ---
    // We need to find a split point between row (mid-1) and row (mid).
    // Let cut at (mid-1) be at col j (relative c1).
    // Let cut at (mid) be at col p (relative c1), where p >= j.
    // We need s1 (from fwd) + s2 (from bwd) = target.
    
    // Precompute suffix unions of bwd for fast lookup
    vector<BitSet> suff_bwd(cols);
    BitSet accum;
    for (int k = cols - 1; k >= 0; --k) {
        accum |= bwd[k];
        suff_bwd[k] = accum;
    }

    for (int j = 0; j < cols; ++j) {
        // Iterate through all possible sums s1 reachable at the end of the top half
        for (int s1 = fwd[j]._Find_first(); s1 < MAX_SUM; s1 = fwd[j]._Find_next(s1)) {
            int s2 = target - s1;
            if (s2 >= 0 && suff_bwd[j].test(s2)) {
                // Found a valid combination of sums.
                // Now find the specific p >= j that contributed s2
                int p = -1;
                for (int search_p = j; search_p < cols; ++search_p) {
                    if (bwd[search_p].test(s2)) {
                        p = search_p;
                        break;
                    }
                }
                
                // Recursively solve for the two halves
                solve_recursive(r1, c1, mid, c1 + j, s1);
                solve_recursive(mid, c1 + p, r2, c2, s2);
                return;
            }
        }
    }
}

void solve() {
    cin >> N >> M;
    // Reset globals
    is_transposed = false;
    
    // Read grid
    // If N < M, we transpose implicitly to optimize memory/speed
    // Transpose: N' = M, M' = N.
    // If we transpose, "Down" becomes "Right" and "Right" becomes "Down".
    if (N < M) {
        is_transposed = true;
        swap(N, M);
    }

    // Precompute row prefix sums
    // row_pref[i][j] = sum of ones in first j cells of row i
    row_pref.assign(N, vector<int>(M + 1, 0));
    int total_sum = 0;
    
    for (int i = 0; i < N; ++i) { // Iterating rows of logical N (maybe transposed)
        for (int j = 0; j < M; ++j) { // Iterating cols of logical M
            int val;
            cin >> val;
            if (is_transposed) {
                // If transposed, input reading fills (j, i) but we store as (i, j) logic
                // Actually, standard input is row by row. 
                // We need to buffer input if we want to transpose on the fly.
                // But simplified: Read all, then build `row_pref`.
            }
        }
    }
    
    // Correct input reading with transpose logic
    // We re-read input carefully or use a buffer.
    // Given N*M limit, flat vector is best.
    vector<int> grid_flat(N * M);
    // Rewind cin? No.
    // We cannot rewind cin. We must buffer.
    // We already swapped N, M in variables. 
    // If is_transposed was true, the INPUT has M rows and N cols.
    // Wait, the input gives dimensions first. 
    // If I swapped N and M, I need to be careful.
    
    // Let's restart logic with original dimensions R, C
    int R, C;
    if (is_transposed) { R = M; C = N; } // Original Input dims
    else { R = N; C = M; }

    vector<vector<int>> raw_grid(R, vector<int>(C));
    total_sum = 0;
    for(int i=0; i<R; ++i) {
        for(int j=0; j<C; ++j) {
            cin >> raw_grid[i][j];
            total_sum += raw_grid[i][j];
        }
    }

    // Build row_pref based on logical N, M
    for(int i=0; i<N; ++i) {
        for(int j=0; j<M; ++j) {
            int val = is_transposed ? raw_grid[j][i] : raw_grid[i][j];
            row_pref[i][j+1] = row_pref[i][j] + val;
        }
    }

    // --- Step 1: Find best Target Sum ---
    // Run minimal Forward DP to get all reachable sums at the end
    // dp[k] = reachable sums ending at row i, col k
    vector<BitSet> dp(M + 1);
    
    // Init row 0
    for(int k=0; k<=M; ++k) dp[k].set(get_ones(0, k));
    
    for(int i=1; i<N; ++i) {
        vector<BitSet> next_dp(M + 1);
        BitSet pref;
        for(int k=0; k<=M; ++k) {
            pref |= dp[k];
            next_dp[k] = pref << get_ones(i, k);
        }
        dp = move(next_dp);
    }

    BitSet final_sums;
    for(int k=0; k<=M; ++k) final_sums |= dp[k];

    long long max_prod = -1;
    int best_target = 0;
    
    for(int s = final_sums._Find_first(); s < MAX_SUM; s = final_sums._Find_next(s)) {
        long long current_prod = (long long)s * (total_sum - s);
        if (current_prod > max_prod) {
            max_prod = current_prod;
            best_target = s;
        }
    }

    cout << max_prod << "\n";

    // --- Step 2: Reconstruct Path ---
    cut_col.assign(N, 0);
    solve_recursive(0, 0, N, M, best_target);

    // --- Step 3: Generate Output String ---
    string path = "";
    // We are on logical grid N x M.
    // We start at (0,0). Logical current column = 0.
    int curr_c = 0;
    for(int i=0; i<N; ++i) {
        // We need to reach cut_col[i] in this row before moving Down
        // cut_col[i] is the number of cells taken.
        // So we occupy columns 0 to cut_col[i]-1.
        // The boundary is at index cut_col[i].
        // We move Right until we hit the boundary.
        while(curr_c < cut_col[i]) {
            path += (is_transposed ? 'D' : 'R');
            curr_c++;
        }
        // Then we move Down (to next row)
        // Except for the very last row? 
        // No, path goes from top-left to bottom-right (N, M)
        // This involves N 'D' moves and M 'R' moves.
        // The 'D' move finishes row i.
        path += (is_transposed ? 'R' : 'D');
    }
    // After N 'D's (logical), we might still need to traverse remaining 'R's
    while(curr_c < M) {
        path += (is_transposed ? 'D' : 'R');
        curr_c++;
    }

    // The constructed path has N 'D's and M 'R's (logically).
    // If transposed, 'D'->'R' and 'R'->'D', so M 'D's and N 'R's. Correct.
    cout << path << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while(t--) {
            solve();
        }
    }
    return 0;
}