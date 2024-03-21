#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		int a[n + 1], b[n + 1], mx1[n + 1], mx2[n + 1], mx3[n + 1], mx4[n + 1];
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		for (int i = 0; i <= n; i++) mx1[i] = mx2[i] = mx3[i] = mx4[i] = -1e18;
		
		int dp[n + 1][k + 1]; memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++) for (int j = 1; j <= min(i, k); j++) {
			mx1[i - j] = max(mx1[i - j], dp[i - 1][j - 1] - b[i] - a[i]);
			mx2[i - j] = max(mx2[i - j], dp[i - 1][j - 1] + b[i] - a[i]);
			mx3[i - j] = max(mx3[i - j], dp[i - 1][j - 1] - b[i] + a[i]);
			mx4[i - j] = max(mx4[i - j], dp[i - 1][j - 1] + b[i] + a[i]);
			
			dp[i][j] = dp[i - 1][j];
            dp[i][j] = max(dp[i][j], b[i] + a[i] + mx1[i - j]);
            dp[i][j] = max(dp[i][j], b[i] - a[i] + mx2[i - j]);
            dp[i][j] = max(dp[i][j], -b[i] + a[i] + mx3[i - j]);
            dp[i][j] = max(dp[i][j], -b[i] - a[i] + mx4[i - j]);
		}
		
		cout << dp[n][k] << '\n';
	}
}
