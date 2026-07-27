#include <bits/stdc++.h>
using namespace std;
 
void solve(){
	int x, y;
	cin >> x >> y;
	cout << ((x % 2 == 1 && y % 2 == 1) ? "NO" : "YES") << '\n';
}
 
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}