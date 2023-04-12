#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	pair<int, int> a[n];
	for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
	ll dp[n+1][m+1];
	for (int i = 0; i <= n; i++) {
		int w = a[i-1].first, v = a[i-1].second;
		for (int j = 0; j <= m; j++) {
			if (i == 0) dp[i][j] = 0;
			else if (j < w) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w] + v);
		}
	}
	cout << dp[n][m];
}
