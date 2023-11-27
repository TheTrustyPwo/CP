#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, q, k, dp[305][5005];
pair<int, int> a[305];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> q >> k;
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	
	for (int i = 0; i <= n; i++) {
		int w = a[i - 1].first, v = a[i - 1].second;
		for (int j = 0; j <= k; j++) {
			if (i == 0) dp[i][j] = 0;
			else if (j < w) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w] + v);
		}
	}
	
	int cur = dp[n][k];
	while (q--) {
		int w, v; cin >> w >> v;
		if (w <= k && dp[n][k - w] + v > cur) cout << "YES\n";
		else cout << "NO\n";
	}
}
