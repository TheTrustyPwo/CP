#include <bits/stdc++.h>
using namespace std;
#define int long long

int bs(int a[], int n) {
	int l = 1, r = 1e18, ans;
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		int start = a[0], cnt = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] - start > m || i == n - 1) {
				start = a[i];
				cnt++;
			}
		}
		
		if (cnt <= 3) {
			r = m - 1;
			ans = m;
		} else l = m + 1;
	}
	
	return ans;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int x[n], y[n];
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	
	sort(x, x + n);
	sort(y, y + n);
	
	int ans = max(bs(x, n), bs(y, n));
	cout << ans;
}
