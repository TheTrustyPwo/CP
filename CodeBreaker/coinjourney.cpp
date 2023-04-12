#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	ll pre[n]; pre[0] = a[0];
	for (int i = 1; i < n; i++) pre[i] = pre[i - 1] + a[i];
	ll mx[n]; mx[0] = pre[0];
	for (int i = 1; i < n; i++) mx[i] = max(mx[i - 1], pre[i]);
	while (q--) {
		int t; cin >> t;
		auto it = lower_bound(mx, mx + n, t);
		cout << (it == mx + n ? -1 : it - mx + 1) << "\n";
	}
}
