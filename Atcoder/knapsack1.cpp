#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, w; cin >> n >> w;
	int a[n + 1][2]; for (int i = 1; i <= n; i++) cin >> a[i][0] >> a[i][1];
	int dp[n + 1][w + 1];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= w; j++) {
		if (i == 0 || j == 0) dp[i][j] = 0;
		else {
			dp[i][j] = dp[i - 1][j];
			if (j >= a[i][0]) dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i][0]] + a[i][1]);
		}
	}
	cout << dp[n][w];
}
