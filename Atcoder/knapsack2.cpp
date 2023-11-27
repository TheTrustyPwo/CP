#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, w; cin >> n >> w;
	int a[n + 1][2], sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i][0] >> a[i][1];
		sum += a[i][1];
	}
	
	int dp[n + 1][sum + 1];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= sum; j++) {
		if (j == 0) dp[i][j] = 0;
		else if (i == 0) dp[i][j] = 1e9;
		else {
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i][1]) dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i][1]] + a[i][0]);
		}
	}
	
	int ans = 0;
	for (int i = 0; i <= sum; i++) {
		if (dp[n][i] <= w) ans = max(ans, i);
	}
	
	cout << ans;
}
