#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9 + 7;

int n, k;
int dp[5005][5005];

int solve(int n, int k) {
	if (k < 0) return 0;
	if (n == 0 && k == 0) return 1;
	if (n == 0) return 0;
	if (dp[n][k] != -1) return dp[n][k];
	dp[n][k] = ((solve(n, k - n) % m) + (solve(n - 1, k) % m)) % m;
	return dp[n][k];
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i <= 5000; i++)
		for (int j = 0; j <= 5000; j++)
			dp[i][j] = -1;
	cout << solve(n, k);
}
