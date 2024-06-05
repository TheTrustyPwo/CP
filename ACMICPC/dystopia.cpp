#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int x, y, n; cin >> x >> y >> n;
	int dp[n + 1][2]; dp[0][0] = x, dp[0][1] = y;
	for (int i = 1; i <= n; i++) {
		int w38 = (i >= 38 ? dp[i - 38][1] : 0);
		int w18 = (i >= 18 ? dp[i - 18][1] : 0);
		
		dp[i][0] = dp[i - 1][0] + (w38 - w18) / 2;
		dp[i][1] = dp[i - 1][1] + (w38 - w18) / 2;
	}
	
	cout << "Final men: " << dp[n][0] << '\n';
	cout << "Final women: " << dp[n][1] << '\n';
}
