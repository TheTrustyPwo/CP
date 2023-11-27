#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n + 1], b[n + 1];
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	
	int dp[n + 1][4]; dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
	// 0 - You defeat 1
	// 1 - You defeat 2
	// 2 - Syy defeat 1
	// 3 - Syy defeat 2
	for (int i = 1; i <= n; i++) {
		dp[i][0] = min(dp[i - 1][2], dp[i - 1][3]) + a[i];
		dp[i][1] = dp[i - 1][0] + a[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
		dp[i][3] = dp[i - 1][2] + b[i];
	}
	
	cout << min({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});
}
