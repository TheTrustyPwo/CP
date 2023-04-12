#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		pair<int, int> a[n];
		for (int i = 0; i < n; i++) cin >> a[i].first;
		for (int i = 0; i < n; i++) cin >> a[i].second;
		sort(a, a + n);
		int suf[n]; suf[n - 1] = a[n - 1].second;
		for (int i = n - 2; i >= 0; i--) suf[i] = min(suf[i + 1], a[i].second);
		
		int damage = 0;
		while (k > 0) {
			damage += k;
			int idx = upper_bound(a, a + n, make_pair(damage, 1000000000)) - a;
			if (idx >= n) break;
			k -= suf[idx];
		}
		
		if (damage >= a[n - 1].first) cout << "YES\n";
		else cout << "NO\n";
	}
}
