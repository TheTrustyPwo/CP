#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m;
int k[305], t[305], s[305];
int dp[305][305][1005];

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> k[i] >> t[i] >> s[i];
	
	for (int i = n; i >= 0; i--) for (int j = n; j >= 0; j--) for (int h = 0; h <= m; h++) {
		if (h == 0 || i == n || j < s[i]) dp[i][j][h] = 0;
		else {
			int ans = -1e9;
			if (h >= t[i]) ans = max(ans, dp[i+1][j+1][h-t[i]] + k[i]);
			ans = max(ans, dp[i+1][j][h]);
			dp[i][j][h] = ans;
		}
	}

	cout << max(0, dp[0][0][m]);
}
