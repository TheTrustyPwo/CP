#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[3005];
int dp[3005][3005][2];

int solve(int l, int r, int player) {
	if (l == r) return (player == 0 ? a[l] : -a[l]);
	if (dp[l][r][player] != -1) return dp[l][r][player];
	int val = 0;
	if (player == 0) {
		val = max(solve(l, r - 1, 1) + a[r], solve(l + 1, r, 1) + a[l]);
	} else {
		val = min(solve(l, r - 1, 0) - a[r], solve(l + 1, r, 0) - a[l]);
	}
	dp[l][r][player] = val;
	return val;
}


int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) dp[i][j][0] = dp[i][j][1] = -1;
	cout << solve(0, n - 1, 0);
}
