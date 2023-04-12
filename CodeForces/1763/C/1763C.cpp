#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		ll a[n]; for (int i = 0; i < n; i++) cin >> a[i];
		if (n == 2) cout << max(a[0] + a[1], 2 * abs(a[1] - a[0]));
		else if (n == 3) cout << max({a[0] + a[1] + a[2], 3 * abs(a[1] - a[0]), 3 * abs(a[2] - a[1]), 3 * a[0], 3 * a[2]});
		else cout << *max_element(a, a + n) * n;
		cout << '\n';
	}
}
