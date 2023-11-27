#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[2005], dp[2005][2005][2];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for (int i = 0; i <= n; i++) for (int j = 0; j <= k; j++) {
		if (i == 0 && j == 0) dp[i][j][0] = dp[i][j][1] = 1e9;
		else if (i == 0) dp[i][j][0] = dp[i][j][1] = -1e9;
		else {
			dp[i][j][0] = max(dp[i-1][j][0], min(dp[i-1][j][1], + a[i] - a[i-1]));
			dp[i][j][1] = max(min(dp[i-1][j-1][0], a[i] - a[i-1]), dp[i-1][j-1][1]);
		}
	}
	
	cout << max(dp[n][k][0], dp[n][k][1]);
}
