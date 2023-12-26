#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, a[5005], dp[5005][5005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	
	for (int l = n; l >= 1; l--) for (int r = 1; r <= n; r++) {
		if (l == r) dp[l][r] = 0;
		else dp[l][r] = a[r] - a[l] + min(dp[l + 1][r], dp[l][r - 1]);
	}
	
	cout << dp[1][n];
}
