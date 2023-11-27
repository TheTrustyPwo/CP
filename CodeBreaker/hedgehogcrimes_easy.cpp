#include <bits/stdc++.h>
using namespace std;
const int m = 998244353;

int n, k, u, dp[3005][3005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	dp[0][0] = dp[0][1] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i][0] = u = (dp[i - 1][0] + dp[i - 1][1]) % m;
		dp[i][1] = (i < k) ? u : (u - dp[i - k][0] + m) % m;
	}
	cout << dp[n][1];
}
