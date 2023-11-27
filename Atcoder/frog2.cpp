#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];
	int dp[n + 1]; dp[0] = 0; dp[1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i] = 1e9;
		for (int j = 1; j <= k; j++) {
			if (i > j) dp[i] = min(dp[i], dp[i - j] + abs(a[i] - a[i - j]));
		}
	}
	cout << dp[n];
}
