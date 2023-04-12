#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[5005][5005][2], c[5005], s[5005];

int solve(int n, int k, bool f) {
	if (n == 0 && !f) return 0;
	if ((n == 0 && f) || k < 0) return -1e9;
	if (dp[n][k][f] != -1) return dp[n][k][f];
	if (f) dp[n][k][f] = max(solve(n - 1, k - n, 1) + s[n], solve(n - 1, k - 1, 0) + s[n] - c[n] * c[n - 1]);
	else dp[n][k][f] = max(solve(n - 1, k, 0), solve(n, k, 1) - c[n] * c[n + 1]);
	return dp[n][k][f];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	c[0] = c[n + 1] = s[0] = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> c[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	
	cout << max(solve(n, k, 0), solve(n, k, 1));
}
