#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll a[n], b[n];
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		ll x = *min_element(a, a + n), y = *min_element(b, b + n);
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			ll m = min(a[i] - x, b[i] - y);
			ans += (m + a[i] - x - m + b[i] - y - m);
		}
		cout << ans << '\n';
	}
}
