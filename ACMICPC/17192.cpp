#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int a[n + 1]; for (int i = 1; i <= n; i++) cin >> a[i];
	int dp[405][405];
	
	int sum = 0, mx = 0;
	for (int i = 1; i <= n; i++)
		sum += a[i], mx = max(mx, a[i]), dp[i][0] = mx * i - sum;
		
	for (int i = 0; i <= n; i++) for (int j = 1; j <= k; j++) {
		if (i == 0) dp[i][j] = 0;
		
		int sum = 0, mx = 0; dp[i][j] = 1e9;
		for (int x = i; x > 0; x--) {
			mx = max(mx, a[x]); sum += a[x];
			dp[i][j] = min(dp[i][j], dp[x - 1][j - 1] + mx * (i - x + 1) - sum);
		}
	}
	
	cout << dp[n][k];
}
