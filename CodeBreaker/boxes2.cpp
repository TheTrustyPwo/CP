#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int l[n + 2]; for (int i = 1; i <= n + 1; i++) cin >> l[i];
	int r[n + 1]; for (int i = 1; i <= n; i++) cin >> r[i];
	
	int suf[n + 2]; suf[n + 1] = 0;
	for (int i = n; i >= 2; i--) suf[i] = suf[i + 1] + (l[i] * r[i]);
	
	int dp[n + 2]; dp[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		dp[i] = dp[i + 1] + (l[i + 1] * r[i]);
		int sum = suf[i + 1] + r[i] * l[n + 1];
		for (int j = n; j > i; j--) {
			dp[i] = max(dp[i], dp[j + 1] + sum);
			sum = sum - (r[i] * l[j + 1]) - (r[j] * l[j]) + (r[i] * l[j]);
		}
	}
	
	int ans = 0, sum = 0;
	for (int i = 1; i <= n + 1; i++) {
		ans = max(ans, dp[i] + sum);
		sum += l[i] * r[i];
	}
	
	cout << ans;
}
