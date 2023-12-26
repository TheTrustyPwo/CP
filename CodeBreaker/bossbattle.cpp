#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	pair<int, int> a[n]; for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	while (q--) {
		int x, y; cin >> x >> y;
		int cur = 0;
		while (y > 0 && cur < n) {
			y -= (a[cur].first * ((a[cur].second / x) + (a[cur].second % x != 0)));
			cur++;
		}
		if (y > 0) cout << -1 << '\n';
		else cout << cur << '\n';
	}
}
