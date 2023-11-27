#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int mn[n]; mn[0] = a[0];
	for (int i = 1; i < n; i++) mn[i] = min(mn[i - 1], a[i]);
	
	while (q--) {
		int v; cin >> v;
		int index = lower_bound(mn, mn + n, v, greater<int>()) - mn;
		if (index == n) cout << -1 << ' ';
		else cout << index + 1 << ' ';
	}
}
