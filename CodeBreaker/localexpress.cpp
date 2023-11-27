#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9 + 7;

int n, k, u, dp[1000005][2];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	dp[0][0] = dp[0][1] = dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = u = (dp[i - 1][0] + dp[i - 1][1]) % m;
		dp[i][1] = (i < k) ? u : (u - dp[i - k][0] + m) % m;
	}
	cout << dp[n][1];
}
