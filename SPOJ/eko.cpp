#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int mx = 0; for (int i = 0; i < n; i++) mx = max(mx, a[i]);
	
	int l = 0, r = mx, ans = 0;
	while (l <= r) {
		int m = l + (r - l) / 2;
		
		int chop = 0;
		for (int i = 0; i < n; i++) chop += max(0ll, a[i] - m);
		
		if (chop >= k) {
			ans = m;
			l = m + 1;
		} else r = m - 1;
	}
	
	cout << ans;
}
