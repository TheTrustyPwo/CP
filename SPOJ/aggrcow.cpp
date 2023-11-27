#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, c; cin >> n >> c;
		int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
		sort(a, a + n);
		
		int l = 1, r = a[n - 1] - a[0], ans = 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			
			int cur = a[0], cnt = 1;
			for (int i = 1; i < n; i++) {
				if (a[i] - cur >= m) {
					cnt++;
					cur = a[i];
				}
			}
			
			// cout << m << ' ' << cnt << '\n';
			
			if (cnt >= c) {
				ans = m;
				l = m + 1;
			} else r = m - 1;
		}
		
		cout << ans << '\n';
	}
}
