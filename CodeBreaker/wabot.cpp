#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	vector<vector<ll>> v(3e6);
	for (ll i = 0; i < n; i++) {
		ll a, b; cin >> a >> b;
		v[a].push_back(b);
	}
	ll ans = 0;
	for (int i = 0; i <= 3e6; i++) {
		sort(v[i].begin(), v[i].end());
		for (int j = 1; j < v[i].size(); j += 2) {
			ll res = v[i][j] + v[i][j - 1];
			ans += res;
			v[i + 1].push_back(res);
		}
	}
	cout << ans;
}
