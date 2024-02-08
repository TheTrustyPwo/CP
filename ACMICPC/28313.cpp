#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	
	int ans[n + 1]; fill(ans, ans + n + 1, 1e9);
	for (int i = 0; i < n; i++) {
		int l = i, r = i, cur = 0;
		while (l >= 0 && r < n) {
			cur += abs(a[l] - a[r]);
			ans[r - l + 1] = min(ans[r - l + 1], cur);
			l--; r++;
		}
		if (i == n - 1) continue;
		l = i, r = i + 1, cur = 0;
		while (l >= 0 && r < n) {
			cur += abs(a[l] - a[r]);
			ans[r - l + 1] = min(ans[r - l + 1], cur);
			l--; r++;
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
