#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, e, k, x; cin >> n >> e >> k >> x;
	pair<int, int> a[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i].second;
	for (int i = 1; i <= n; i++) cin >> a[i].first;
	
	int dp[n + 1][10005];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= 10000; j++) dp[i][j] = -1e18;
	for (int i = 0; i <= n; i++) {
		for (int s = 0; s <= a[i].second; s++) {
			for (int j = s; j <= 10000; j++) {
				if (i == 0) { dp[i][j] = (j == 0 ? e : -1e18); continue; }
				dp[i][j] = max(dp[i][j], min(e + (j - s) * k, dp[i - 1][j - s] + x) - a[i].first * s);
				if (dp[i][j] < 0) dp[i][j] = -1e18;
			}
		}
	}
	
	// for (int i = 0; i <= n; i++) { for (int j = 0; j <= 15; j++) cout << dp[i][j] << ' '; cout << '\n'; }
	
	int ans = 0;
	for (int i = 0; i <= 10000; i++) if (dp[n][i] == -1e18) {
		ans = i - 1;
		break;
	}
	cout << ans;
}
