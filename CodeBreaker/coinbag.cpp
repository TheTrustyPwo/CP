#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, m; cin >> n >> m;
	int w[n], v[n];
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	
	int dp[n + 1][m + 1];
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0) dp[i][j] = 0;
			else if (j < w[i - 1]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
		}
	}
	
	cout << dp[n][m];
}
