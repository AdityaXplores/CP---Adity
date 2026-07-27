#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int tc; cin >> tc;
	while(tc--) {
		vector<pair<int, char>> a = {{0,'R'},{0,'G'},{0,'B'}};
		for(auto &x : a) cin >> x.first;

		string ans = ""; int n = 0;
		while(true) {
			sort(a.rbegin(), a.rend());
			int pick = -1;
			for(auto j : {0, 1, 2}) {
				if(!a[j].first) continue;
				if(n >= 1 && a[j].second == ans[n-1]) continue;
				if(n >= 3 && a[j].second == ans[n-3]) continue;
				if(pick == -1) { pick = j; continue; }
				if(n >= 2 && a[pick].first == a[j].first && a[j].second == ans[n-2]) {
					pick = j;
				}
			}
			if(pick == -1) break;
			ans.push_back(a[pick].second); n++;
			a[pick].first--;
		}

		cout << ans << "\n";
	}

	return 0;
}