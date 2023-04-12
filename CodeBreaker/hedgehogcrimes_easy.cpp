#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 998244353;

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int n, k; cin >> n >> k;
	int dp[n + 1][k + 1][2];
	
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j == 0) {
				dp[i][j][0] = dp[i][j][1] = 0;
			} else if (i == 0 || j == 1) {
				dp[i][j][0] = 1, dp[i][j][1] = 0;
			} else {
				dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % m;
				dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j - 1][1]) % m;
			}
		}
	}
	
	cout << (dp[n][k][0] + dp[n][k][1]) % m;
}
