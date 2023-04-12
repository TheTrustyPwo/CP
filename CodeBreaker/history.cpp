#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, s; cin >> n >> s;
	int a[n]; for (int i = 0; i < n; i++) cin >> a[i];
	while (s--) {
		int b[n]; for (int i = 0; i < n; i++) cin >> b[i];
		int dp[n+1][n+1];
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				if (i == 0 || j == 0) dp[i][j] = 0;
				else if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
				else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		cout << dp[n][n] << endl;
	}
}
