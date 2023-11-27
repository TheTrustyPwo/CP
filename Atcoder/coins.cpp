#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n; cin >> n;
	long double p[n + 1]; for (int i = 1; i <= n; i++) cin >> p[i];
	
	int least = n / 2 + 1;
	long double dp[n + 1][least + 1];
	for (int i = 0; i <= n; i++) for (int j = 0; j <= least; j++) {
		if (j == 0) dp[i][j] = 1;
		else if (i == 0) dp[i][j] = 0;
		else dp[i][j] = dp[i - 1][j - 1] * p[i] + dp[i - 1][j] * (1 - p[i]);
	}
	
	cout << fixed << setprecision(10) << dp[n][least];
}
