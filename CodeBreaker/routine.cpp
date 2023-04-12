#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll n, m; cin >> n >> m;
	ll t[n], a[n];
	for (ll i = 0; i < n; i++) cin >> t[i];
	for (ll i = 0; i < n; i++) cin >> a[i];
	for (ll i = 0; i < n; i++) t[i]--;
	while (m--) {
		ll q; cin >> q;
		auto it = lower_bound(t, t + n, q);
		cout << a[distance(t, prev(it))] << endl;
	}
}
