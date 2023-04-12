#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	ll a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	ll dp[2][n];
	dp[0][0] = 0, dp[1][0] = a[0];
	for (int i = 1; i < n; i++) {
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		dp[1][i] = dp[0][i - 1] + a[i];
	}
	cout << max(dp[0][n - 1], dp[1][n - 1]);
}
