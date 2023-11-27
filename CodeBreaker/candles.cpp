#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];

	int ans = 1e18;
	for (int i = 0; i < n - k + 1; i++) {
		ans = min(ans, a[i + k - 1] - a[i] + min(abs(a[i]), abs(a[i + k - 1])));
	}
	
	cout << (ans == 1e18 ? 0 : ans);
}
