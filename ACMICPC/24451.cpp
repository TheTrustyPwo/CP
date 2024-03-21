#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k, a[3005], dp[3005];

int get(int l, int r) {
	auto it = max_element(a + l, a + r);
	if (l == r) return *it;
	int idx = it - a;
	int mx = 0; for (int i = l; i <= r; i++) if (i != idx) mx = max(mx, a[i]);
	return *it + mx;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	
	int ans = 0;
	for (int i = 1; i <= n; i += k) {
		ans += get(i, i + k - 1);
	} cout << ans;
}
