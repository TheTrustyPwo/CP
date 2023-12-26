#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int ans = -1e18;
	for (int mask = 1; mask < (2 << m); mask++) {
		int cnt = 0, res = 0;
		for (int i = 0; i <= m; i++) {
			if ((mask & (1 << i)) > 0) {
				if (cnt >= n) { cnt = -1; break; }
				res += a[cnt++] * __builtin_popcount(i);
			}
		}
		if (cnt == n) ans = max(ans, res);
	}
	cout << ans;
}
