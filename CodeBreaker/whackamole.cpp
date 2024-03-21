#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int l = 0, r = 1e18, ans = -1;
	while (l <= r)  {
		int m = l + (r - l) / 2;
		int c = m, p = n - 1;
		for (int i = k - 1; i >= 0; i--) {
			while (p >= 0 && c < a[p])
				p--;
			c -= p + 1;
		}
		if (c > 0) {
			r = m - 1;
			ans = m;
		} else l = m + 1;
	}
	
	cout << ans;
}
