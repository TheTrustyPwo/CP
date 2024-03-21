#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];
	
	int dp[n + 1];
	int mx[n + 1]; dp[0] = 0;
	for (int i = 0; i <= n; i++) mx[i] = -1e9;
	for (int i = 1; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (mx[a[i]] != -1e9)
			dp[i] = max(dp[i], mx[a[i]] + i);
		mx[a[i]] = max(mx[a[i]], dp[i - 1] - i + 1);
	}
	cout << dp[n];
}
