#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	int ans = 0;
	for (int i = k - 1; i < n; i += k) {
		if (a[i] <= 0) break;
		ans += a[i];
	}
	cout << ans;
}
