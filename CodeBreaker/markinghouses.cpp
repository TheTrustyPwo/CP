#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n + 1]; a[0] = -1e9;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a, a + n + 1);
	
	int dp[n + 1][k + 1][2];
	dp[0][0][0] = dp[0][0][1] = 1e9;
	for (int i = 1; i <= k; i++) dp[0][i][0] = dp[0][i][1] = -1e9;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j][0] = max(dp[i - 1][j][0], min(dp[i - 1][j][1], a[i] - a[i - 1]));
			dp[i][j][1] = max(dp[i - 1][j - 1][1], min(dp[i - 1][j - 1][0], a[i] - a[i - 1]));
		}
	}
	
	cout << max(dp[n][k][0], dp[n][k][1]);
}
