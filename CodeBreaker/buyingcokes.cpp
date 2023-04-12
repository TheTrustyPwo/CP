#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[155][105][55];

int solve(int c, int n1, int n5, int n10) {
	if (c == 0) return 0;
	else if (dp[c][n5][n10] != -1) return dp[c][n5][n10];
	else if (n5 == 0 && n10 == 0) return c * 8;
	
	int result = c * 8;

	if (n10 > 0) result = min(result, 1 + solve(c - 1, n1 + 2, n5, n10 - 1));
	if (n10 > 0 && n1 >= 3) result = min(result, 4 + solve(c - 1, n1 - 3, n5 + 1, n10 - 1));
	if (n5 >= 2) result = min(result, 2 + solve(c - 1, n1 + 2, n5 - 2, n10));
	if (n5 > 0 && n1 >= 3) result = min(result, 4 + solve(c - 1, n1 - 3, n5 - 1, n10));

	dp[c][n5][n10] = result;
	return dp[c][n5][n10];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int t, c, n1, n5, n10; cin >> t;
	while (t--) {
		cin >> c >> n1 >> n5 >> n10;
		memset(dp, -1, sizeof(dp));
		cout << solve(c, n1, n5, n10) << "\n";
	}
}
