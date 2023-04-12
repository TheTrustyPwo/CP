#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int h[n]; for (int i = 0; i < n; i++) cin >> h[i];
	int dp[n]; dp[0] = 0;
	for (int i = 1; i < n; i++) {
		dp[i] = INT_MAX;
		for (int j = max(0, i - k); j < i; j++) {
			dp[i] = min(dp[i], dp[j] + abs(h[j] - h[i]));
		}
	}
	cout << dp[n-1];
}
