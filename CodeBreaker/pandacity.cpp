#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, b; cin >> n >> b;
	if (b < n - 1) { cout << -1; return 0; }
	
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	
	int ans = 0;
	for (int i = 1; i <= min(n - 1, b); i++) {
		ans += a[0];
		ans += a[i];
	}
	
	cout << ans;
}
