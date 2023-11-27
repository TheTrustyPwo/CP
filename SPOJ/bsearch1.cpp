#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, q; cin >> n >> q;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	while (q--) {
		int v; cin >> v;
		int l = 0, r = n - 1, ans = -1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (a[m] == v) {
				ans = m;
				r = m - 1;
			} else if (a[m] > v) {
				r = m - 1;
			} else l = m + 1;
		}
		cout << ans << '\n';
	}
}
