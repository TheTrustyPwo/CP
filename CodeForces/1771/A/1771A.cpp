#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
		int mx = *max_element(a, a + n), mn = *min_element(a, a + n);
		int cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == mx) cnt0++;
			if (a[i] == mn) cnt1++;
		}
		int ans = cnt0 * cnt1 * 2;
		cout << ans << "\n";
	}
}
