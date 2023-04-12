#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	int a[n+1]; for (int i = 0; i < n; i++) cin >> a[i]; a[n] = 0;
	int dp[n+1]; dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		dp[i] = (i + 1) * (i + 1);
		for (int j = 0; j < i; j++)
			if (a[j] >= a[i]) dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
	}
	cout << dp[n];
}
