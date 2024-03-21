#include <bits/stdc++.h>
using namespace std;
#define int long long

int mn[200005];
pair<pair<int, int>, int> g[200005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int ans = 1e18; fill(mn, mn + 200000, 1e18);
	for (int i = 1; i < n; i++) {
		int a, b, c; cin >> a >> b >> c;
		mn[a] = min(mn[a], c);
		g[i] = make_pair(make_pair(a, b), c);
	}
	for (int i = 1; i < n; i++) {
		int a = g[i].first.first, b = g[i].first.second, c = g[i].second;
		cout << b << ' ' << mn[b] << '\n';
		if (a == 1) ans = min({ans, 3 * c, c + mn[b]});
		else ans = min(ans, 2 * c);
	}
	if (n == 2) cout << -1;
	else cout << ans;
}
