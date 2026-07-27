#include <bits/stdc++.h>
using namespace std;

void solve(){
	int N;
	cin >> N;
	vector<pair<double,double> > tasks;
	for(int i = 0; i < N; i++){
		double c, p;
		cin >> c >> p;
		tasks.push_back({c, p});
	}
	double frac = 0;
	for(int i = N-1; i >= 0; i--){
		auto [c, p] = tasks[i];
		frac = max(c + (1 - p / 100) * frac, frac);
	}
	cout << fixed << setprecision(10);
	cout << frac << '\n';
}

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int T;
	cin >> T;
	while(T--) solve();
}