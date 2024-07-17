#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	int seats = (n + 1) / 2;
	sort(a, a + n, greater<int>());
	int ans = 0;
	for (int i = 0; i < seats; i++) {
		if (a[i] <= 0) break;
		ans += a[i];
	}
	cout << ans;
}
